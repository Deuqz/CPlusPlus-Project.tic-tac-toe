#!/bin/bash
set -ue

set +e
"$@" >mytest-demo-out.tmp 2>mytest-demo-err.tmp
RET_CODE=$?
set -e

echo -e "\e[7mStdout was (expected to be empty):\e[0m"
cat mytest-demo-out.tmp
echo -e "\e[7mStderr was:\e[0m"
cat mytest-demo-err.tmp

echo "mytest-demo exited with $RET_CODE"
[ "$RET_CODE" == "1" ]

! [ -s mytest-demo-out.tmp ]
sed -re "s/[^ ]+(demo[123]\.cpp:[0-9]+)/\1/g" -i mytest-demo-err.tmp

EXPECTED_DEMO_1=$(cat <<EOF
Running "Demo1.cpp test case 1"...
Running "Demo1.cpp test case 2"...
CHECK(2 * 2 == 5) at demo1.cpp:8 failed!
EOF
)
EXPECTED_DEMO_2=$(cat <<EOF
Running "Demo2.cpp test case 1"...
Running "Demo2.cpp test case 2"...
CHECK(2 * 2 == 5) at demo2.cpp:8 failed!
Running "Demo2.cpp test case with multiple failures and messages"...
CHECK(2 * 2 == 5) at demo2.cpp:13 failed!
    message: demo2-msg2
CHECK(2 * 2 == 5) at demo2.cpp:15 failed!
EOF
)
EXPECTED_DEMO_3=$(cat <<EOF
Running "Demo3.cpp test case with complex calls"...
CHECK(2 * 2 == 5) at demo3.cpp:15 failed!
CHECK(2 * 2 == 7) at demo3.cpp:6 failed!
EOF
)
EXPECTED_TAIL=$(cat <<EOF
===== Tests passed: 2/6 =====
EOF
)

echo -e "\e[7mChecking outputs...\e[0m"
diff <(grep -i demo1 mytest-demo-err.tmp) <(echo "$EXPECTED_DEMO_1")
diff <(grep -i demo2 mytest-demo-err.tmp) <(echo "$EXPECTED_DEMO_2")
diff <(grep -i demo3 mytest-demo-err.tmp) <(echo "$EXPECTED_DEMO_3")
diff <(tail -n 1 mytest-demo-err.tmp) <(echo "$EXPECTED_TAIL")
diff <(cat mytest-demo-err.tmp | wc -l) <(echo -e "$EXPECTED_DEMO_1\n$EXPECTED_DEMO_2\n$EXPECTED_DEMO_3\n$EXPECTED_TAIL" | wc -l)
echo All ok.

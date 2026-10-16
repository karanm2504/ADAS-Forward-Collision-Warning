
import subprocess

compile_result = subprocess.run(
    ["gcc", "-Wall", "-Wextra", "-std=c11",
     "ttc_calculator.c", "-o", "fcw_test"],
    capture_output=True,
    text=True
)

if compile_result.returncode != 0:
    print("COMPILATION FAILED")
    print(compile_result.stderr)
    raise SystemExit(1)

test_cases = [
    (10, "CRITICAL"),
    (25, "WARNING"),
    (50, "SAFE"),
    (15, "CRITICAL"),
    (16, "WARNING"),
    (30, "WARNING"),
    (31, "SAFE")
]

for distance, expected_status in test_cases:
    result = subprocess.run(
        ["./fcw_test"],
        input=str(distance) + "\n",
        capture_output=True,
        text=True,
        timeout=5
    )

    expected_line = f"Status: {expected_status}"

    if result.returncode == 0 and expected_line in result.stdout:
        print(f"Distance {distance}m: TEST PASSED")
    else:
        print(f"Distance {distance}m: TEST FAILED")
        print(result.stdout)
        print(result.stderr)

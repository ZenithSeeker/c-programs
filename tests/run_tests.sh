#!/usr/bin/env bash
# Hand-checked cases for both programs. Run from the repo root: make test
set -u
cd "$(dirname "$0")/.."
pass=0; fail=0

check() {  # name, expected, actual
    if [[ "$2" == "$3" ]]; then
        pass=$((pass + 1))
    else
        fail=$((fail + 1))
        printf 'FAIL: %s\n  expected: %q\n  got:      %q\n' "$1" "$2" "$3"
    fi
}

# last board printed by automata, rows joined with '/'
final_board() { ./automata/automata "$@" | awk 'NF{last=$0; rows=rows"/"$0} !NF{rows=""} END{print substr(rows,2)}'; }

# ---------- automata
# a lone cell: its 8 neighbours each see 1 live neighbour, the cell itself sees 0
check "lone cell, band [1,8]" "111/101/111" \
    "$(final_board --total=1 --step=1 --lower=1 --upper=8 '000/010/000')"
# corner cell without wrap: only its 3 in-bounds neighbours light up
check "corner, no wrap" "010/110/000" \
    "$(final_board --total=1 --step=1 --lower=1 --upper=1 '100/000/000')"
# with wrap on a 3x3 board every other cell is a neighbour of the corner
check "corner, wrap" "011/111/111" \
    "$(final_board --total=1 --step=1 --lower=1 --upper=1 --wrap '100/000/000')"
check "zero steps prints the input" "0110/1001" \
    "$(final_board --total=0 --step=1 --lower=2 --upper=3 '0110/1001')"
check "ragged board rejected" "Board must be a rectangle." \
    "$(./automata/automata --total=1 --step=1 --lower=1 --upper=3 '011/10')"
check "oversized board rejected" "Board can be at most 10 x 10." \
    "$(./automata/automata --total=1 --step=1 --lower=1 --upper=3 00000000000/00000000000)"
check "bad characters rejected" "Board must contain only 0, 1 and /." \
    "$(./automata/automata --total=1 --step=1 --lower=1 --upper=3 0120/0000)"

# ---------- combinations: 3 items, choose 2
count() { ./combinations/counting "$@" combinations/birds.txt /dev/stdout | wc -l | tr -d ' '; }
check "C(3,2)"                   3 "$(count -c -o -n 2)"
check "P(3,2)"                   6 "$(count -p -o -n 2)"
check "combinations with reps"   6 "$(count -c -r -n 2)"
check "3^2 with order and reps"  9 "$(count -p -r -n 2)"
check "C(3,2) contents" "flightless_fred passenger_percy
flightless_fred speckled_jim
passenger_percy speckled_jim" \
    "$(./combinations/counting -c -o -n 2 combinations/birds.txt /dev/stdout | awk '{print ($1<$2)?$1" "$2:$2" "$1}' | sort)"
check "missing file is an error, not a crash" "1" \
    "$(./combinations/counting -c -o -n 2 nope.txt /dev/stdout >/dev/null; echo $?)"

echo "$pass passed, $fail failed"
[[ $fail -eq 0 ]]

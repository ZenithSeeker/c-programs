# c-programs

Two small command-line programs in C99, from my first-year systems programming unit at the
University of Sydney (INFO1910), tidied up with input validation and a test script.

```bash
make        # builds both
make test   # builds, then runs the hand-checked test cases
```

## `automata`: a configurable cellular automaton

A two-dimensional, outer-totalistic cellular automaton on a board of up to 10 × 10 cells. Each
step, a cell is alive if its number of live neighbours is between `--lower` and `--upper`
(inclusive). Edges are hard by default, or wrap around into a torus with `--wrap`.

```bash
./automata/automata --total=3 --step=1 --lower=1 --upper=8 "00000/00000/00100/00000/00000"
```

| Option | Meaning |
|---|---|
| `--total=N` | number of steps to run |
| `--step=K` | print the board every K steps |
| `--lower=L`, `--upper=U` | live-neighbour band that keeps or makes a cell alive |
| `--wrap` | wrap edges (torus) |
| board | rows of `0`/`1` separated by `/` |

Boards that are ragged, oversized or contain other characters are rejected with a message,
rather than read out of bounds.

## `combinations`: enumerate selections from a list

Reads space-separated items from a file and writes every selection of `n` of them, as
permutations or combinations, with or without repetition.

```bash
./combinations/counting -c -o -n 2 combinations/birds.txt /dev/stdout
```

| Option | Meaning |
|---|---|
| `-p` / `-c` | permutations (order matters) or combinations |
| `-r` / `-o` | with or without repetition |
| `-n NUM` | how many items per selection |

It enumerates every n-digit number in base k (k = number of items) and keeps the ones that meet
the constraints. Simple and exhaustive, which is fine for small inputs.

Item names are stored as byte offsets into the input file, not copied, and are read back with
`fseek` when each selection is written out.

## Layout

Each program keeps its headers in `lib/` and its sources in `src/`, with a makefile that builds
object files into `build/`.

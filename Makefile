.PHONY: all test clean

all:
	$(MAKE) -C automata
	$(MAKE) -C combinations

test: all
	./tests/run_tests.sh

clean:
	rm -rf automata/build automata/automata combinations/build combinations/counting

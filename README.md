
# Tests for 42's project libasm


<strong>Undefined behaviors are not tested.</strong>

[REGV] means potential crash -> means 0.

---

## Workflow

```
$> git clone git***.com/owner/libasm
$> cd libasm && make re
$> git clone https://github.com/mmeisson/tests_libasm
$> cd tests_libasm && make re
$> ./libfts_test
# let the magic happens

$> ./test_cat file_name[s]
# let the magic happens

```

---

## Usage

```
$> ./libfts_test --help
Usage :: ./libfts_test [--help] [--verbose MINIMAL|NORMAL|FULL] [ tests_name ]
```

### verbose modes :
0. Minimal
  * Display results of tests per function without details
1. Normal
  * Display results of sub tests without details
2. FULL
  * Display results of tests plus the tests that has been done

Tip for lazy  : `/libfts_test --verbose 0|1|2` works to

---

## Codes

<span style="color: green;">[WORKS]</span> self explanatory.

<span style="color: red;">[REGV]</span> the function violated registers calling convention. ( Means potential crash -> 0 ).

<span style="color: red;">[ERROR]</span> the function did not worked well.

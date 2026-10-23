# Number to Words

A small command-line program written in C that converts non-negative integers into English words using a text dictionary. It includes my [Libft](https://github.com/santiagosilvestri/c-libft) and compiles without downloads.

Supports up to 45 significant decimal digits, leading zeros and custom dictionary entries. The C sources follow the 42 coding style and passed official Norminette 3.3.60.

## Build and usage

Requires a C compiler, `make` and a POSIX environment such as Linux or macOS.

```sh
make
./numwords 42
# forty two
./numwords 123456
# one hundred twenty three thousand four hundred fifty six
./numwords dictionaries/en.dict 1001
# one thousand one
```

Usage is `./numwords [dictionary] number`. Run from the repository root to use the default dictionary; otherwise provide its path explicitly.

```sh
make clean   # remove object files
make fclean  # remove objects, executable and static library
make re      # rebuild from scratch
```

## How it works

The number remains a string, avoiding integer overflow. Exact dictionary entries take precedence, except for multiplier keys such as `100` and `1000`. Larger numbers are split recursively into a prefix, a scale and a remainder: `123456` becomes `123` × `1000` + `456`. Tens and units use direct lookups.

`src/` contains the converter, dictionary reader, validation and output routines. `include/` contains the shared header, `dictionaries/` the English vocabulary, and `libft/` the complete library source. Libft handles common string and memory operations; local helpers join words and manage temporary allocations.

The bundled Libft is revision `9652abc5ad4c0fbe887b206d64aa541b576b3d3f`. Only whitespace in `ft_lstsize.c` was adjusted for Norminette; its logic is unchanged.

## Dictionary and limits

```text
0: zero
1: one
20: twenty
21: twenty-one
100: hundred
1000: thousand
```

Custom dictionaries need the entries required by the requested number. Blank lines, full-line `#` comments, CRLF and surrounding whitespace are accepted. Duplicate or malformed entries, embedded NUL bytes and noncanonical keys such as `01` are rejected. Limits are 100 entries and 2047 bytes per line.

Only non-negative integers are supported, from `0` to `10^45 - 1`. English output omits hyphens and `and` unless provided by an exact custom entry. Changing dictionary words does not implement another language's grammar.

Invalid arguments print `Error`; dictionary, allocation or conversion failures print `Dict Error`. Both use standard output and return status `1`. Output failures also return a nonzero status.

## Author

**Santiago Silvestri** - `sasilves`

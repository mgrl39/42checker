As an evaluator, you should write or provide a `main` function that checks the following:

- The return value of the `get_next_line` function is `NULL` in case of an error.
- Otherwise, the function returns the read line, always ending with a `\n`.

Test all combinations of the following rules:
- Large `BUFFER_SIZE` (> 1024)
- Small `BUFFER_SIZE` (< 8, and 1)
- `BUFFER_SIZE` equal to the size of the line to be read
- A 1-character offset (+/-) between `BUFFER_SIZE` and the line length
- Reading from `stdin`
- Reading from a file
- (Multiple/Simple) long line (2k+ characters)
- (Multiple/Simple) short line (<4 characters, and 1)
- (Multiple/Simple) empty line
These tests should allow you to verify the validity of the student's project. If there is an error, the evaluation stops here.

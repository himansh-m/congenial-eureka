#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {
      ++nl;
    }
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}

// The bugs start appearing when instead of using enter then hitting the end of
// file signal with ctrl+D, I end the file while writing a word by hitting
// ctrl+D twice to signal EOF. In the above case of ending while writing a word,
// the character count nc is not displayed, nl shows the number of words and nw
// shows the number of newlines which is the opposite of what they are supposed
// to track and most of the times one of the two value is wrong. Thus, the above
// mentioned way is how and where I would aim to find a bug.

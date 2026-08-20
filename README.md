# LFSR
Linear Feedback Shift Register

Create maximum length sequences, over a range of word lengths.  Tries all combinations of parameters, in a brute force strategy to identify successful combinations.  Typical console output is shown in this MacOS terminal window. Similar results on Linux and Windows with minor syntax changes.

```
MarksiMac:Projects williamm$ cd LFSR/
MarksiMac:LFSR williamm$ rm lfsr.txt
MarksiMac:LFSR williamm$ g++ lfsr.cpp
MarksiMac:LFSR williamm$ ./a.out > lfsr.txt
MarksiMac:LFSR williamm$ head lfsr.txt
(1, 3)
(2, 3)
(1, 4)
(3, 4)
(2, 5)
(3, 5)
(1, 6)
(5, 6)
(1, 7)
(3, 7)
```

This program can take from minutes to hours to complete, depending on your computer and what bit length you want to reach. An Excel spreadsheet is also posted here, which computes several maximum length sequences.

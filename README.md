# EEE 6744 – Hands-on Hardware Security
# Experiment 1 – Buffer Overflow Attack

## Student
**Name:** Sivanesh Murthi, Patrick Craig, Shreejaa Udaya Sekar 
**Course:** EEE6744 – Hands-on Hardware Security  
**Experiment:** Experiment 1 – Buffer Overflow Attack
**Date:** 09/01/2026
---

# 1. Objective

The objective of this experiment is to understand buffer overflow vulnerabilities, demonstrate different types of buffer overflow attacks, observe how memory corruption can affect program execution, and study techniques used to detect and prevent buffer overflow attacks.

The experiment consists of three main parts:

1. Demonstration of different types of buffer overflows.
2. Demonstration of a stack-based buffer overflow attack.
3. Demonstration of function-pointer modification using a buffer overflow.

Additional prevention and detection techniques were also studied:

- Valgrind
- Secure coding
- Compiler-based runtime protection
- Library-based runtime protection
  - Libsafe
  - Libverify
  - Libparanoia

---

# 2. Directory Structure

The experiment files are organized as follows:

```text
Exp1/
│
├── Extra Credit/
│   │
│   ├── secure_coding/
│   │   ├── Screenshots/
│   │   │   ├── secure_coding_1.png
│   │   │   └── secure_coding_2.png
│   │   │
│   │   ├── bo_test_secure
│   │   ├── bo_test_secure.c
│   │   ├── readme.txt
│   │   └── run_secure.pl
│   │
│   └── valgrind/
│       ├── Screenshots/
│       │   ├── valgrind_1.png
│       │   └── valgrind_2.png
│       │
│       ├── bo_test_valgrind
│       ├── bo_test_valgrind_64
│       ├── bo_test_valgrind.c
│       ├── readme.txt
│       └── run_valgrind.pl
│
├── Part 1/
│   ├── Screenshot/
│   │   └── Part 1.png
│   │
│   ├── expt1_1
│   └── expt1_1.c
│
├── Part 2/
│   ├── screenshots/
│   │   └── Part 2.png
│   │
│   ├── ccode
│   └── ccode.c
│
└── Part 3/
    ├── Screenshots/
    │   ├── Part 3_1.png
    │   └── Part 3_2.png
    │
    ├── bo_test
    ├── bo_test_32
    ├── bo_test_32.c
    ├── bo_test.c
    ├── readme.txt
    ├── run_32.pl
    └── run.pl
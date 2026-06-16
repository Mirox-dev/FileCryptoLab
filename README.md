# FileCryptoLab

FileCryptoLab/
├── CMakeLists.txt
├── README.md
├── .gitignore
│
├── docs/
│   ├── project_description.md
│   └── defense_plan.md
│
├── data/
│   ├── input.txt
│   ├── encrypted.txt
│   └── decrypted.txt
│
├── include/
│   └── filecryptolab/
│       ├── core/
│       │   ├── Cipher.h
│       │   ├── CipherType.h
│       │   └── CryptoMode.h
│       │
│       ├── ciphers/
│       │   ├── AffineCipher.h
│       │   ├── XorCipher.h
│       │   └── HillCipher.h
│       │
│       ├── io/
│       │   └── FileManager.h
│       │
│       ├── ui/
│       │   └── ConsoleMenu.h
│       │
│       └── utils/
│           ├── MathUtils.h
│           └── TextUtils.h
│
├── src/
│   ├── main.cpp
│   │
│   ├── ciphers/
│   │   ├── AffineCipher.cpp
│   │   ├── XorCipher.cpp
│   │   └── HillCipher.cpp
│   │
│   ├── io/
│   │   └── FileManager.cpp
│   │
│   ├── ui/
│   │   └── ConsoleMenu.cpp
│   │
│   └── utils/
│       ├── MathUtils.cpp
│       └── TextUtils.cpp
│
└── tests/
    ├── test_affine.cpp
    ├── test_xor.cpp
    └── test_hill.cpp
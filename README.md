# 🖥️ Simpletron

![Language C](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Build CMake](https://img.shields.io/badge/Build-CMake-red?style=for-the-badge&logo=cmake)
![Platform Linux](https://img.shields.io/badge/Platform-Linux-orange?style=for-the-badge&logo=linux)
![License MIT](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)



> 🚀 **A simple virtual computer simulator written in C that implements the Simpletron Machine Language (SML)** 🚀
>
> *Experience the fundamentals of computer architecture through simulation!*

## 📋 Overview

Simpletron is a hypothetical computer with 100 memory locations, an accumulator, and a simple instruction set. It executes programs written in SML (Simpletron Machine Language) using a 4-digit instruction format: 2 digits for the operation code and 2 digits for the operand.

## ✨ Features

- 🎯 **100 memory locations** (00-99) for storing instructions and data
- ⚡ **Accumulator-based architecture** for arithmetic operations
- 🔄 **Interactive program loading** and execution
- 🐛 **Memory dump functionality** for debugging
- 🚀 **Extended instruction set** with logical and immediate operations

## 📖 Instruction Set

### 📥 I/O Operations

- `10` **READ** - Read input into memory location
- `11` **WRITE** - Write memory location to output

### 💾 Memory Operations

- `20` **LOAD** - Load memory into accumulator
- `21` **STORE** - Store accumulator into memory

### 🧮 Arithmetic Operations

- `30` **ADD** - Add memory to accumulator
- `31` **SUBTRACT** - Subtract memory from accumulator
- `32` **DIVIDE** - Divide accumulator by memory
- `33` **MULTIPLY** - Multiply accumulator by memory

### 🔀 Control Flow

- `40` **BRANCH** - Unconditional branch
- `41` **BRANCHNEG** - Branch if accumulator is negative
- `42` **BRANCHZERO** - Branch if accumulator is zero
- `43` **HALT** - Stop execution

### ⚙️ Extended Operations

- `53` **AND** - Logical AND operation
- `54` **OR** - Logical OR operation
- `56-59` **Immediate arithmetic** operations
- `60` **INCREMENT** - Increment memory location

## 🏗️ Architecture

```ascii
┌─────────────────────────────────────────────────────────────┐
│                        SIMPLETRON                          │
├─────────────────────────────────────────────────────────────┤
│  Memory (100 locations)          │  Registers              │
│  ┌─────┬─────┬─────┬─────┐       │  ┌─────────────────────┐ │
│  │ 00  │ 01  │ 02  │ ... │       │  │    Accumulator      │ │
│  ├─────┼─────┼─────┼─────┤       │  │                     │ │
│  │ 10  │ 11  │ 12  │ ... │       │  └─────────────────────┘ │
│  ├─────┼─────┼─────┼─────┤       │  ┌─────────────────────┐ │
│  │ 20  │ 21  │ 22  │ ... │       │  │ Instruction Counter │ │
│  ├─────┼─────┼─────┼─────┤       │  │                     │ │
│  │ ... │ ... │ ... │ 99  │       │  └─────────────────────┘ │
│  └─────┴─────┴─────┴─────┘       │                         │
└─────────────────────────────────────────────────────────────┘
```

## 🛠️ Building and Running

### 🏗️ Using CMake

```bash
mkdir build && cd build
cmake ..
make
./Simplemachine
```

### ⚡ Using GCC directly

```bash
gcc -o simpletron main.c Simpletron_UI.c SML_exe.c Recive_instructions.c Excute.c "Fetch&Decode.c"
./simpletron
```

## 🚀 Usage

1. 🏃 Run the program
2. ⌨️ Enter SML instructions when prompted (format: XXYY where XX is opcode, YY is operand)
3. 🎬 Enter `-99999` to start execution
4. ⏹️ Program will execute until HALT instruction or error

## 💡 Example Program

```sml
+1007  // 📥 READ into location 07
+1008  // 📥 READ into location 08
+2007  // 💾 LOAD from location 07
+3008  // ➕ ADD location 08
+2109  // 💾 STORE result in location 09
+1109  // 📤 WRITE location 09
+4300  // ⏹️ HALT
```

✨ This program reads two numbers, adds them, and displays the result.

## 🤝 Contributing

Contributions are welcome! Feel free to:

- 🐛 Report bugs
- 💡 Suggest new features
- 🔧 Submit pull requests
- 📖 Improve documentation

## 📄 License

This project is licensed under the MIT License.

---



![Star](https://img.shields.io/github/stars/AbdelrahmanElshahat/simpletron?style=social)
![Fork](https://img.shields.io/github/forks/AbdelrahmanElshahat/simpletron?style=social)

*⭐ Star this repository if you found it helpful!*


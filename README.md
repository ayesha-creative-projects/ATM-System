# 🏧 ATM System Simulation

A console-based ATM simulation built with **C++** featuring PIN verification, balance management, deposits, withdrawals, mini statements, and transaction tracking.


## ✨ Technologies

- **C++ 17**
- **Control Structures** (loops, conditionals, switch-case)
- **Standard Library** (`<iostream>`, `<string>`)
- **File Handling** (`<fstream>`)

---

## 🚀 Features

- **PIN Verification** - 3 attempts before ATM lockout
- **Check Balance** - View current account balance
- **Deposit Money** - Add funds (max 5000 per transaction)
- **Withdraw Money** - Withdraw with balance validation
- **Mini Statement** - View last transaction type and amount
- **Transaction Tracking** - Stores last transaction (Deposit/Withdraw)
- **Input Validation** - Prevents invalid amounts and overdrafts
- **Auto Lock** - ATM locks after 3 failed PIN attempts

---

## 📍 The Process

I wanted to build something that mimics a real ATM experience while practicing core C++ concepts. Started with simple balance management, but realized it needed proper authentication and transaction tracking. The 3-attempt PIN system adds security, while the mini statement feature shows how increment/decrement operators work in real scenarios. The deposit limit (5000 per transaction) prevents unrealistic inputs. The switch-case menu structure keeps everything organized and responsive. Built the whole thing to be modular, so each feature (check, deposit, withdraw, statement) works independently while sharing the same balance state.

---

## 🎯 Component Architecture

- **PIN Verification** - While loop with 3 attempt counter
- **Main Menu** - Do-while loop with switch-case for 5 operations
- **Check Balance** - Direct balance display
- **Deposit** - Validates amount >0 and ≤5000, updates balance
- **Withdraw** - Checks sufficient balance before deducting
- **Mini Statement** - Shows last transaction type and amount
- **Transaction Tracking** - Stores lastTransactionType ('D'/'W') and amount
- **Exit** - Graceful program termination with thank you message

---

## 🚀 Output
<img width="226" height="340" alt="image" src="https://github.com/user-attachments/assets/7fac7a0b-1e37-48bb-ac7d-85585d263865" />
<img width="203" height="233" alt="image" src="https://github.com/user-attachments/assets/74bc6223-1bbd-4d01-abcf-385285f939b2" />



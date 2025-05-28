
# LGL-MOD-MENU-EASY

📌 **A project that simplifies writing code inside LGL-MOD-MENU using `Dump.cs` data.**

---

## 🚀 Getting Started

1. Download the `hooks.h` file.
2. Place it in your project next to `main.cpp`.
3. Open `main.cpp` and add the following line at the top:

```cpp
#include "hooks.h"
```

---

## 🌟 Features

- Supports all basic data types: `bool`, `int`, `float`, `double`
- Hook with or without offset updates
- Simplified macro-based syntax
- Specifically designed for 32-bit and 64-bit systems

---

## 📂 Jump to Section

- [Offset-based Hooks](#offset-based-hooks)
- [Hooks with Offset + Update](#offset--update-hooks)
- [Void Return Type Hooks](#void-return-type-hooks)
- [Void + Update Hooks](#void--update-hooks)
- [All Hooks Summary](#hooks-summary)

---

## 🔧 Offset-based Hooks

### `ADD_BOOL_HOOK`

Used with boolean values (`true` or `false`).

**Example:**

```cpp
bool mod1 = false;
ADD_BOOL_HOOK(mod1, oldShop, Shop, true);

MSHookFunction(
 (void *)getAbsoluteAddress(targetLibName, 0x123456),
 (void*)Shop,
 (void **) &oldShop);
```

🧠 Applicable for: `ADD_BOOL_HOOK`, `ADD_FLOAT_HOOK`, `CREATE_DOUBLE_HOOK`, `CREATE_INT_HOOK`

> Ensure correct value formats:  
> - `float`: `9999.0f`  
> - `double`: `9999.0`  
> - `int`: Integer value like `123456789`

---

## 🛠️ Offset + Update Hooks

### `ADD_FLOAT_UPDATE_HOOK`

```cpp
bool mod2 = false;

ADD_FLOAT_UPDATE_HOOK(mod2, old_Speed, speed, 0x20, 50.0f);

MSHookFunction(
 (void *)getAbsoluteAddress(targetLibName, 0x123456),
 (void*)speed,
 (void **) &old_speed);
```

🧠 Applicable for:
- `ADD_BOOL_UPDATE_HOOK`
- `ADD_FLOAT_UPDATE_HOOK`
- `ADD_DOUBLE_UPDATE_HOOK`
- `ADD_INT_UPDATE_HOOK`

---

## 🔁 Void Return Type Hooks

### `ADD_DOUBLE_VOID_HOOK`

```cpp
bool mod3 = false;

ADD_DOUBLE_VOID_HOOK(mod3, seedel, old_seedel, 120.0);

MSHookFunction(
 (void *)getAbsoluteAddress(targetLibName, 0x123456),
 (void*)seedel,
 (void **) &old_seedel);
```

🧠 Applicable for:
- `ADD_BOOL_VOID_HOOK`
- `ADD_FLOAT_VOID_HOOK`
- `ADD_DOUBLE_VOID_HOOK`
- `ADD_INT_VOID_HOOK`

---

## 🔄 Void + Update Hooks

### `ADD_INT_VOID_UPDATE_HOOK`

```cpp
bool mod4 = false;

ADD_INT_VOID_UPDATE_HOOK(mod4, old_SpeedGG1, old_SpeedGG2, SpeedGG1, 9999);

old_SpeedGG2 = (void (*)(void *, bool))getAbsoluteAddress(targetLibName,0x12345678);

MSHookFunction(
 (void *)getAbsoluteAddress(targetLibName, 0x123456),
 (void *) SpeedGG1,
 (void **) &old_SpeedGG1);
```

🧠 Applicable for:
- `ADD_BOOL_VOID_UPDATE_HOOK`
- `ADD_FLOAT_VOID_UPDATE_HOOK`
- `ADD_DOUBLE_VOID_UPDATE_HOOK`
- `ADD_INT_VOID_UPDATE_HOOK`

---

## 📋 Hooks Summary

### Offset Hooks

```cpp
ADD_BOOL_HOOK(...);
ADD_FLOAT_HOOK(...);
ADD_DOUBLE_HOOK(...);
ADD_INT_HOOK(...);
```

### Offset + Update Hooks

```cpp
ADD_BOOL_UPDATE_HOOK(...);
ADD_FLOAT_UPDATE_HOOK(...);
ADD_DOUBLE_UPDATE_HOOK(...);
ADD_INT_UPDATE_HOOK(...);
```

### Void Offset Hooks

```cpp
ADD_BOOL_VOID_HOOK(...);
ADD_FLOAT_VOID_HOOK(...);
ADD_DOUBLE_VOID_HOOK(...);
ADD_INT_VOID_HOOK(...);
```

### Void + Update Hooks

```cpp
ADD_BOOL_VOID_UPDATE_HOOK(...);
ADD_FLOAT_VOID_UPDATE_HOOK(...);
ADD_DOUBLE_VOID_UPDATE_HOOK(...);
ADD_INT_VOID_UPDATE_HOOK(...);
```

---

## 🧩 Example Hook Function

For 64-bit
```cpp
A64HookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) hookingBool1, (void **) &old_hookingBool1);
```

For 32-bit:
```cpp
MSHookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) hookingBool1, (void **) &old_hookingBool1);
```

---

🎨 Images used in documentation (hosted on GitHub):  
- `Code1.png`, `Code2.png`, `Code3.png`, `1-1.png`, `Code4.png`, `2.png`

---

Made with ❤️ for LGL MOD MENU developers.

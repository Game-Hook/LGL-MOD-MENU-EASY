# LGL-MOD-MENU-EASY

**تتمحور الفكرة حول كتابة الأكواد بشكل سهل وسريع داخل قوائم `LGL-MOD-MENU`، وستتعلم كيف تستخدم جميع البيانات الموجودة في ملف `Dump.cs`.**


**طريقه ربط ملف سهل تحمل ملف `hooks.h` وتروح مشروعك ضيفه يم ملف `main.cpp` وتفتح ملف `main.cpp`ضيف كود التالي**


```cpp
#include "hooks.h"
```


---

## الميزات

- دعم جميع أنواع البيانات الأساسية (`bool`, `int`, `float`, `double`)
- هوك مباشر أو هوك مع تعديل الأوفست
- كتابة مبسطة باستخدام `Macro`
- مخصص لأنظمة 32-بت

---

## ماكروز الدوال التي تعمل مع الأوفست

### # ADD_BOOL_HOOK

**هذا أول نوع من البيانات وهو `bool`، والذي تكون له حالتان فقط: `true` أو `false`.**

#### وتكون الدالة بالشكل التالي:

- public bool Shob() {}
```cpp
ADD_BOOL_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Bool);
```
```cpp
MSHookFunction(
 (void *)getAbsoluteAddress(targetLibName, 0x0000),
 (void*)hook_name_fake_func,
 (void **) &hook_name_point_func);
```
**حيث ان**
- **hook_name |تمثل**
- **bool mod1 = false;**
- **hook_name_point_func | اي اسم تريده سميه بكيفك**
- **hook_name_fake_func | هم اسم بكيف بس كون يختلف عن الاول**
- **edit_Bool | تعديل الذي تختاره من الخيارين اسفل**
- **(true ot false) تعديل واحد من ذني ثنين**
  ---
  
  ### مثال اضافه تفعيله

  
  
**//offset 0x123456**

**public bool Shob() {}**


**اكواد اضيفها في السورس او `main.cpp`**


**bool mod1 = false;**

**ADD_BOOL_HOOK(mod1, oldShop, Shop, true);**

**case 1:**

**mod1 = boolean;**

**break;**


  **وريدك ضيف مكان تفعيلات هاذا الكود**
  
  
  MSHookFunction(
 (void *)getAbsoluteAddress(targetLibName, 0x123456),
 (void*)Shop,
 (void **) &oldShop);
 ### وهاذا الكلام ينطبق على ثلاثه دوال

## #ADD_FLOAT_HOOK

**//offset 0x123456**

**public speed Shob() {}**

## #CREATE_DOUBLE_HOOK**

**//offset 0x123456**

**public bool Damage() {}**

## #CREATE_INT_HOOK**

**//offset 0x123456**

**public int Jump() {}**

**حيث يكون الاختلاف بسيط فقط في نوع بينات وتاخذ مناسب مع انتباه ان تعديل لازم يكون مناسب حسب نوع حيث ان `float = 9999.0f` حيث لازم ان تضع له بلنهايه `0f.` ونوع ثاني `double` تنهيه فقط `0.` int اعداد صحيه مثل `123456789`**

---
## الان نجي للبيانات التي تكون باهذي الطريقه والتي تحتاج الى `offset` و `offset Update`

### # ADD_FLOAT_UPDATE_HOOK
```cpp
ADD_FLOAT_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Float);
```
```cpp
MSHookFunction(
 (void *)getAbsoluteAddress(targetLibName, 0x0000),
 (void*)hook_name_fake_func,
 (void **) &hook_name_point_func);
```


## مثال للفهم 
**bool mod2 = false;**


**case 2:**


**mod2 = boolean;**


**break;**


**public float speed;//0x20**


**//offset 0x123456**


**public void update (){}**


**ADD_FLOAT_UPDATE_HOOK(mod2, old_Speed, speed, 0x20, 50.0f);// اوفست اول**


`MSHookFunction(
 (void *)getAbsoluteAddress(targetLibName, 0x123456),
 (void*)speed,
 (void **) &old_speed);`

**وهاذا الكلام ينطبق على الدوال التاليه**


## #ADD_BOOL_UPDATE_HOOK
## #ADD_DOUBLE_UPDATE_HOOK
## #ADD_INT_UPDATE_HOOK

---
## الان نجي الى الدوال التي تكون void 
## # ADD_DOUBLE_VOID_HOOK
`ADD_DOUBLE_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Double)`

**مثال للفهم**

**bool mod3 = false;**


**case 3:**


**mod3 = boolean;**


**break;**



**//offset 0x123456**

**public void speed (int value){}**

**ADD_DOUBLE_VOID_HOOK(mod3, seedel, old_seedel, 120.0)**

```cpp
MSHookFunction(
 (void *)getAbsoluteAddress(targetLibName, 0x123456),
 (void*)seedel,
 (void **) &old_seedel);
```

**وينطبق هاذا على الدوال التاليه**

## #ADD_BOOL_VOID_HOOK
## #ADD_FLOAT_VOID_HOOK
## #ADD_INT_VOID_HOOK

---
### وهاذا اخر نوع الي هو نوع void بس يحتاج Update
## #ADD_INT_VOID_UPDATE_HOOK

**`ADD_INT_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Int);`**

**مثال للفهم**

**bool mod4 = false;**


**case 4:**


**mod4 = boolean;**


**break;**



**//offset 0x123456**

**public void Update (){}**

**//offset 0x12345678**

**public void speed (int value){}**

**ADD_INT_VOID_UPDATE_HOOK(mod4, old_SpeedGG1, old_SpeedGG2, SpeedGG1, 9999);**
```cpp
old_SpeedGG2 = (void (*)(void *, bool))getAbsoluteAddress(targetLibName,0x12345678);
MSHookFunction((void *)getAbsoluteAddress(targetLibName, 0x123456), (void *) SpeedGG1, (void **) &old_SpeedGG1);
```


**وينطبق هاذا على الدوال التاليه**

## #ADD_BOOL_VOID_UPDATE_HOOK
## #ADD_FLOAT_VOID_UPDATE_HOOK
## #ADD_DOUBLE_VOID_UPDATE_HOOK

---

## ملخص سريع جميع البيانات وطرق 
**اوفسيت فقط**

```cpp
ADD_BOOL_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Bool);
```
```cpp
ADD_FLOAT_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Float);
```
```cpp
ADD_DOUBLE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Double);
```
```cpp
ADD_INT_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Int);
```

**اوفسيت مع Update**

```cpp
ADD_BOOL_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Bool);
```
```cpp
ADD_FLOAT_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Float);
```
```cpp
ADD_DOUBLE_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Double);
```
```cpp
ADD_INT_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Int);
```

**اوفسيت من نوع void**

```cpp
ADD_BOOL_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Bool);
```
```cpp
ADD_FLOAT_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Float);
```
```cpp
ADD_DOUBLE_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Double);
```
```cpp
ADD_INT_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Int);
```
**اوفسيت من نوع void ويحتاج Update**

```cpp
ADD_BOOL_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Bool);
```
```cpp
ADD_FLOAT_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Float);
```
```cpp
ADD_DOUBLE_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Double);
```
```cpp
ADD_INT_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Int);
```


---
**الدوال المستغدمه**.
![Text](https://github.com/Game-Hook/LGL-MOD-MENU-EASY/blob/main/Code1.png)
```cpp
A64HookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) hookingBool1, (void **) &old_hookingBool1);
```
**32bit**
```cpp
MSHookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) hookingBool1, (void **) &old_hookingBool1);
```
![Text](https://github.com/Game-Hook/LGL-MOD-MENU-EASY/blob/main/Code2.png)
```cpp
A64HookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) hookingBool1, (void **) &old_hookingBool1);
```
**32bit**
```cpp
MSHookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) hookingBool1, (void **) &old_hookingBool1);
```
![Text](https://github.com/Game-Hook/LGL-MOD-MENU-EASY/blob/main/Code3.png)
```cpp
A64HookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) hookingBool1, (void **) &old_hookingBool1);
```
**32bit**
```cpp
MSHookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) hookingBool1, (void **) &old_hookingBool1);
```
![Text](https://github.com/Game-Hook/LGL-MOD-MENU-EASY/blob/main/1-1.png)
```cpp
A64HookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) hookingBool1, (void **) &old_hookingBool1);
```
**32bit**
```cpp
MSHookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) hookingBool1, (void **) &old_hookingBool1);
```
![Text](https://github.com/Game-Hook/LGL-MOD-MENU-EASY/blob/main/Code4.png)
```cpp
A64HookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) hookingBool1, (void **) &old_hookingBool1);
```
**32bit**
```cpp
MSHookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) hookingBool1, (void **) &old_hookingBool1);
```
![Text](https://github.com/Game-Hook/LGL-MOD-MENU-EASY/blob/main/2.png)
```cpp
BoolVoidOffset2 = (void (*)(void *, bool))getAbsoluteAddress(targetLibName,0x000000);
A64HookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) UpdateForBoolVoidOffset1, (void **) &old_UpdateForBoolVoidOffset1);
```
**32bit**
```cpp
BoolVoidOffset2 = (void (*)(void *, bool))getAbsoluteAddress(targetLibName,0x000000);
MSHookFunction((void *)getAbsoluteAddress(targetLibName, 0x000000), (void *) UpdateForBoolVoidOffset1, (void **) &old_UpdateForBoolVoidOffset1);
```

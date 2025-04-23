// فقط لنسخ 32 bit
// For 32-bit systems only

/* Variables for hook offset method */
/* متغيرات لطريقة الهوك باستخدام الأوفست */

//hook_name = bool mod = false;
// hook_name => متغير من نوع bool لتفعيل الهوك أو تعطيله

//hook_name_fake_func || اي اسم بالك
// hook_name_fake_func => اسم الدالة الوهمية اللي ترجع القيمة المعدّلة

//hook_name_point_func || اي اسم بالك بس كون يختلف عن اسم الاول
// hook_name_point_func => مؤشر (pointer) إلى الدالة الأصلية لتحفض القيمه قبل تعديل

//edit_Bool || قيمة تعديل (true or false)
// edit_Bool => القيمة التي يتم إرجاعها إذا تم تفعيل الهوك


// BOOL Hook
#define ADD_BOOL_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Bool) \
bool (*hook_name_point_func)(void *instance); \
bool hook_name_fake_func(void *instance) { \
    if (instance != NULL) { \
        if (hook_name) { \
            return edit_Bool; \
        } \
    } \
    return hook_name_point_func(instance); \
}

// هوك لنوع boolean (قيمة منطقية)


// FLOAT Hook
/* Float type: */
#define ADD_FLOAT_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Float) \
float (*hook_name_point_func)(void *instance); \
float hook_name_fake_func(void *instance) { \
    if (instance != NULL) { \
        if (hook_name) { \
            return edit_Float; \
        } \
    } \
    return hook_name_point_func(instance); \
}

// هوك لنوع float (رقم عشري)


// DOUBLE Hook
/* Double type: */
#define CREATE_DOUBLE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Double) \
double (*hook_name_point_func)(void *instance); \
double hook_name_fake_func(void *instance) { \
    if (instance != NULL) { \
        if (hook_name) { \
            return edit_Double; \
        } \
    } \
    return hook_name_point_func(instance); \
}

// هوك لنوع double (رقم عشري بدقة عالية)


// INT Hook
/* Interger type: */
#define CREATE_INT_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Int) \
int (*hook_name_point_func)(void *instance); \
int hook_name_fake_func(void *instance) { \
    if (instance != NULL) { \
        if (hook_name) { \
            return edit_Int; \
        } \
    } \
    return hook_name_point_func(instance); \
}

// هوك لنوع int (عدد صحيح)


//كملنا من جميع الدوال التي تعمل مع اوفسيت
// Done defining all functions that work with offset
//##################################################################################################################################
//##################################################################################################################################
/* Hooking field offset method */
/* طريقة هوك باستخدام أوفست الحقول (المتغيرات داخل الكائن) */
/* طريقة هوك باستخدام أوفست الحقول (المتغيرات داخل الكائن) */
/* Bool type: */
// BOOL مع أوفست
#define ADD_BOOL_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Bool) \
void (*hook_name_point_func)(void *instance); \
void hook_name_fake_func(void *instance) { \
    if (instance != NULL) { \
        if (hook_name) { \
            *(bool *) ((uint32_t) instance + offsetFOR) = edit_Bool; \
        } \
    } \
    return hook_name_point_func(instance); \
}

/* Float type: */
// FLOAT مع أوفست
#define ADD_BOOL_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Float) \
void (*hook_name_point_func)(void *instance); \
void hook_name_fake_func(void *instance) { \
    if (instance != NULL) { \
        if (hook_name) { \
            *(float *) ((uint32_t) instance + offsetFOR) = edit_Float; \
        } \
    } \
    return hook_name_point_func(instance); \
}

/* Double type: */
// DOUBLE مع أوفست
#define ADD_DOUBLE_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Double) \
void (*hook_name_point_func)(void *instance); \
void hook_name_fake_func(void *instance) { \
    if (instance != NULL) { \
        if (hook_name) { \
            *(double *) ((uint32_t) instance + offsetFOR) = edit_Double; \
        } \
    } \
    return hook_name_point_func(instance); \
}

/* Integer type: */
// INT مع أوفست
#define ADD_INT_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Int) \
void (*hook_name_point_func)(void *instance); \
void hook_name_fake_func(void *instance) { \
    if (instance != NULL) { \
        if (hook_name) { \
            *(int *) ((uint32_t) instance + offsetFOR) = edit_Int; \
        } \
    } \
    return hook_name_point_func(instance); \
}

//##################################################################################################################################
//##################################################################################################################################
/* Hooking void (without update offset) */
/* هوك لدوال void (بدون تعديل مباشر على الأوفست داخل الكائن) */

/* Bool void type: */
/* نوع دالة تستقبل متغير bool وتُرجع void */
#define ADD_BOOL_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Bool) \
void (*hook_name_point_func)(void *instance, bool value); \
void hook_name_fake_func(void *instance, bool value) { \
    if (instance != NULL) { \
        if (hook_name) { \
            hook_name_point_func(instance, edit_Bool); \
            return; \
        } \
    } \
    hook_name_point_func(instance, value); \
}


/* Float void type: */
/* نوع دالة تستقبل متغير float وتُرجع void */
#define ADD_FLOAT_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Float) \
void (*hook_name_point_func)(void *instance, float value); \
void hook_name_fake_func(void *instance, float value) { \
    if (instance != NULL) { \
        if (hook_name) { \
            hook_name_point_func(instance, edit_Float); \
            return; \
        } \
    } \
    hook_name_point_func(instance, value); \
}


/* Double void type: */
/* نوع دالة تستقبل متغير double وتُرجع void */
#define ADD_DOUBLE_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Double) \
void (*hook_name_point_func)(void *instance, double value); \
void hook_name_fake_func(void *instance, double value) { \
    if (instance != NULL) { \
        if (hook_name) { \
            hook_name_point_func(instance, edit_Double); \
            return; \
        } \
    } \
    hook_name_point_func(instance, value); \
}


/* Int void type: */
/* نوع دالة تستقبل متغير int وتُرجع void */
#define ADD_INT_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Int) \
void (*hook_name_point_func)(void *instance, int value); \
void hook_name_fake_func(void *instance, int value) { \
    if (instance != NULL) { \
        if (hook_name) { \
            hook_name_point_func(instance, edit_Int); \
            return; \
        } \
    } \
    hook_name_point_func(instance, value); \
}






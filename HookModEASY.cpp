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


/* Hooking field offset method */
/* طريقة هوك باستخدام أوفست الحقول (المتغيرات داخل الكائن) */















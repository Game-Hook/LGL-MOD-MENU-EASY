# LGL-MOD-MENU-EASY
LGL-MOD-MENU-EASY
pam

# ADD_BOOL_HOOK

ADD_FLOAT_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Float)
CREATE_DOUBLE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Double)
CREATE_INT_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Int)

// ===== ماكروز تحديث المتغيرات باستخدام الأوفست =====
ADD_BOOL_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Bool)
ADD_BOOL_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Float) // مكرر بنفس الاسم
ADD_DOUBLE_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Double)
ADD_INT_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Int)

// ===== ماكروز دوال void بدون تعديل مباشر =====
ADD_BOOL_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Bool)
ADD_FLOAT_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Float)
ADD_DOUBLE_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Double)
ADD_INT_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Int)

// ===== ماكروز دوال void مع تعديل =====
ADD_BOOL_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Bool)
ADD_FLOAT_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Float)
ADD_DOUBLE_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Double)
ADD_INT_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Int)

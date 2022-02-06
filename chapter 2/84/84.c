/*
 * 第84题：填写下列程序的返回值，这个程序测试第一个参数是否小于等于第二个参数
 * 假定函数f2u返回一个无符号32位整数，其位表示与浮点参数相同
 * 两个参数都不是NAN 且两种 0 看作相等
*/

// int float_le(folat x, float y)
// {
//     unsigned ux = f2u(x);
//     unsigned uy = f2u(y);

//     unsigned sx = ux >> 31;
//     unsigned sy = uy >> 31;

//     return _____;
// }

/*
 * 解答：
 * 由于浮点数在正数上是升序的，负数上降序
 * 当符号位正负不同时直接比较符号位
 * 否则需要看升降序
 * sx == sy ? (sx == 0 ? ux <= uy : ux >= uy) : sx > sy;
*/
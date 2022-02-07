/*
 * 第89题：在一个int和float都为32位、double为64位的机器上运行程序
 * 随机产生正整数x,y,z并将其转换成double类型
 * //double dx = x;
 * 
 * 指出下面的表达式是否恒定为1
 * 
 * 1. (float) x == (float) dx
 * 2. dx - dy == (double) (x - y)
 * 3. (dx + dy) + dz == dx + (dy + dz)
 * 4. (dx * dy) * dz == dx * (dy * dz)
 * 5. dx / dx == dz / dz
*/

/*
 * 解答：
 * 注意：dx,dy,dz是由整数转换的到，不会出现精度损失
 * 
 * 1. 正确的，int到double不会舍入
 * 2. 不一定，当x很大，y很小时，dx-dy会产生精度损失
 * 3. 正确，虽然浮点数不具有结合性，但是此处的浮点数是由int转换得到
 * 满足结合性
 * 4. 正确，int转换得到的数不会是极小的小数，因此溢出则同时溢出
 * 5. 不正确如dx = 1.0, dz = 0.0
*/
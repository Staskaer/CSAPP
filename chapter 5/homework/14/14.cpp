
/*
编写6x1的循环展开
*/
void inner4(vec_ptr u, vec_ptr v, data_t *dest)
{
    long i;
    long length = vec_length(u);
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = (data_t)0;
    for (i = 0; i < length - 6; i += 6)
    {
        sum = sum + udata[i] * vdata[i] + udata[i + 1] * vdata[i + 1] + udata[i + 2] * vdata[i + 2] + udata[i + 3] * vdata[i + 3] + udata[i + 4] * vdata[i + 4] + udata[i + 5] * vdata[i + 5];
    }
    for (; i < length; i++)
    {
        sum = sum + udata[i] * vdata[i];
    }
    *dest = sum;
}

/*
加法和乘法都达到满流水状态CPE值最小，但是加法下界为0.5，乘法下界为1.0
所以CPE最小值为1.0

而循环展开没有消除掉数据依赖，因此不能突破下界


*/
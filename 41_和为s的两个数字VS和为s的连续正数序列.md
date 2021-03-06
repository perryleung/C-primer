### 题目：
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? 
输出描述：
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

题目一：
输入一个递增排序的数组和一个数字s，在数组中查找两个数，让他们的和正好是S，如果有多对则输出任意一对即可；
{1、2、4、7、11、15}，s = 15，则输出 4、11

因为是排序数组，所以可以用两个指针指向头尾，指针之和大于s，则尾指针--，指针之和小于s，则头指针++
```c++
//=====课本代码
bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2)
{
    bool found = false;
    if(length < 2 || num1 == NULL || num2 == NULL)
        return found;
    int head = 0;
    int tail = length - 1;
    while(head < tail)
    {
        int curSum = data[head] + data[tail];
        if(curSum == sum)
        {
            *num1 = data[head];
            *num2 = data[tail];
            found = true;
            break;
        }else if(curSum < sum)
            head++;
        else
            tail--;
    }
    return true;
}

//问题2，找序列中两个数，因为是两个，所以两个指针中的头指针只要最大到(s+1)/2即可
void PrintSequence(int head, int tail)
{
    for(int i = head; i <= tail; i++)
        printf("%d ", i);
    printf("\n");
}
void FindContinuousSequence(int sum)
{
    if(sum < 3)
        return; // 正数序列，要至少两个数，因此至少有 1，2，小于 3的就舍去
    int head = 1;
    int tail = 2;
    int middle = (sum + 1) / 2;
    int curSum = head + tail; // 小于sum时增加tail，大于sum时增加small
    while(head < middle)
    {
        if(curSum == sum)
            PrintSequence(head, tail);
        while(curSum > sum && head < middle)
        {
            curSum -= head;
            head++;
            if(curSum == sum)
                PrintSequence(head, tail);
        }
        tail++;
        curSum += tail;
    }
}
//=====课本思路以及自己提交
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > ret;
        if(sum < 3)
            return ret;
        int left = 1;
        int right = 2;
        int curSum = left + right;
        while(left <= sum / 2){
            if(curSum == sum){
                vector<int> tmp;
                for(int i = left; i <= right; i++)
                    tmp.push_back(i);
                ret.push_back(tmp);
                curSum -= left;
                left++;
                right++;
                curSum += right;
            }else if(curSum < sum){
                right++;
                curSum += right;
            }else{
                curSum -= left;
                left++;
            }
        }
        return ret;
    }
};

```






















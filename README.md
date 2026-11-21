# algorithm-notes

蓝桥杯 / 算法竞赛备赛笔记。C 语言手写经典算法，每个文件独立可编译，注释里写清思路、复杂度和易错点。

## 目录结构

```text
algorithm-notes/
├── README.md
├── docs/
│   └── muban.c                             # 新题模板（文件头注释格式）
├── sort/
│   ├── xuanzepaixu.c                       # 选择排序
│   └── maopaopaixu.c                       # 冒泡排序
├── search/
│   └── erfenchazhao.c                      # 二分查找
├── number/
│   ├── sushu.c                             # 素数判断
│   └── chaifenshuzi.c                      # 拆分数字
├── two_pointers/
│   └── liangduanhuiju.c                    # 字符串两端向中间汇聚
└── date/
    └── jisuanmounianmouyueyoujitian.c      # 某年某月有多少天
```

## 题目索引

| 专题 | 文件 | 核心思想 | 时间 | 空间 | 易错点 |
|---|---|---|---|---|---|
| 排序 | `sort/xuanzepaixu.c` | 每轮选最小值放到未排序区首位 | O(n²) | O(1) | 记录的是下标；外层 n-1 轮 |
| 排序 | `sort/maopaopaixu.c` | 相邻逆序交换，最大值冒到末尾 | O(n²) | O(1) | 内层 `j < n-1-i`，防 `arr[n]` 越界 |
| 查找 | `search/erfenchazhao.c` | 有序区间折半收缩 | O(log n) | O(1) | `left <= right`；mid 防溢出 |
| 数论 | `number/sushu.c` | 试除到 √n | O(√n) | O(1) | 1 不是素数；`i <= n / i` |
| 数位 | `number/chaifenshuzi.c` | `%10` 取末位，`/10` 去掉 | O(log n) | O(1) | n=0、负数要特判 |
| 双指针 | `two_pointers/liangduanhuiju.c` | left/right 向中间收缩 | O(n) | O(n) | `right = strlen(s)-1` |
| 日期 | `date/jisuanmounianmouyueyoujitian.c` | 月份天数打表 + 闰年 +1 | O(1) | O(1) | 闰年规则；数组 0 号位占位 |

## 编译运行

以冒泡排序为例（PowerShell）：

```powershell
gcc -std=c11 -Wall -Wextra sort/maopaopaixu.c -o maopaopaixu.exe
.\maopaopaixu.exe
```

输入：

```text
4
5 3 8 1
```

输出：

```text
1 3 5 8
```

## 代码约定

- 文件名用全拼小写，和 `lessons` 保持一致（如 `maopaopaixu.c`）
- 文件头统一写：题目、考点、思路、复杂度、易错点，模板见 `docs/muban.c`
- 大括号 Allman 风格，左右对齐
- 数组长度宏统一用 `MAX_SIZE`
- 注释用中文，程序输出用英文（避免 Windows 控制台编码问题）
- 每个文件只有一个 `main`，保证能独立编译

## 更新计划

- [x] 选择排序、冒泡排序
- [ ] 插入排序、归并排序、快速排序
- [ ] 前缀和、差分
- [ ] DFS / BFS、并查集
- [ ] 动态规划入门
- [ ] C++ STL 常用容器

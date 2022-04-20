// #include <bits/stdc++.h>
// #include <sstream>
// #include <string>
// using namespace std;

// void fastIO()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
// }

// int productSumHelper(vector<any> array, int level)
// {
//     // Write your code here.
//     int result = 0;
//     for (auto e : array)
//     {
//         if (e.type() == typeid(vector<any>))
//         {
//             result += productSumHelper(any_cast<vector<any>>(e), level + 1);
//         }
//         else
//         {
//             result += any_cast<int>(e);
//         }
//     }
//     return result * level;
// }

// int productSum(vector<any> array)
// {
//     return productSumHelper(array, 1);
// }

// int main()
// {
//     fastIO();
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     vector<any> s = {1, 2, 3, 4};
//     int result = productSum(s);
//     cout << result << endl;
//     return 0;
// }

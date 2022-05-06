#include <bits/stdc++.h>
using namespace std;
typedef tuple<double, double, double, string, double> splat; // x, y, v, color, radius
typedef list<splat> painting;

const double PI = 3.141592653589793238463;
const double E = 1e-5;

bool isInside(double a, double b, splat sp)
{
    // middle of the splat is (x, y)
    double x = get<0>(sp);
    double y = get<1>(sp);
    // radius of the splat is r
    double r = get<4>(sp);
    double temp = pow((a - x), 2) + pow((b - y), 2);
    double sqr = sqrt(temp);
    if (sqr < r)
    {
        return true;
    }
    return false;
}

int main()
{
    list<string> output;

    int c;
    cin >> c;
    while (c-- > 0)
    {
        int n;
        cin >> n;

        double x, y, v, r;
        string color;
        painting p;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> v >> color;
            r = sqrt(v / PI);
            p.push_front(make_tuple(x, y, v, color, r)); // important to push front
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            bool flag = false;
            for (auto item : p)
            {
                if (isInside(x, y, item))
                {
                    flag = true;
                    output.push_back(get<3>(item));
                    break;
                }
            }
            if (!flag)
            {
                output.push_back("white");
            }
        }
    }
    for (auto item : output)
    {
        cout << item << endl;
    }
    return 0;
}
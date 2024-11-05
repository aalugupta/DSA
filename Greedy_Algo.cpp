// // Activity_Selection_problem

#include <bits/stdc++.h>

using namespace std;

void activity_selection(vector<int> start, vector<int> fin)
{
    sort(fin.begin(), fin.end());
    int count = 1;

    int safe_start_time = fin[0];

    for (int i = 0; i < fin.size(); i++)
    {
        int curr_start_time = start[i];
        if (curr_start_time >= safe_start_time)
        {
            count++;
            safe_start_time = fin[i];
        }
    }
    cout << count;
}
bool compare(pair<int, int> k1, pair<int, int> k2)
{
    return k1.second > k2.second;
}
void knapsack_problem(vector<int> values, vector<int> weight, int w)
{
    vector<pair<int, float>> k(values.size(), make_pair(0, 0.0));
    for (int i = 0; i < values.size(); i++)
    {
        float ratio = (float)values[i] / weight[i];
        k[i] = make_pair(weight[i], ratio);
    }
    int value = 0;
    sort(k.begin(), k.end(), compare);

    int i = 0;

    while (w > 0)
    {
        if (k[i].first < w)
        {
            value += k[i].second * k[i].first;
            w -= k[i].first;
            i++;
        }
        else
        {
            value += w * k[i].second;
            w = 0;
        }
    }
    cout << "value:" << value;
}

void min_absolute_difference(vector<int> one, vector<int> two)
{
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    int absDiff = 0;
    for (int i = 0; i < one.size(); i++)
    {
        absDiff += abs(one[i] - two[i]);
    }
    cout << absDiff;
}

void indian_coins(int price, vector<int> arr)
{
    int n = arr.size(), ans = 0;
    vector<int> count;
    for (int i = n - 1; i >= 0; i--)
    {
        //     while (arr[i] <= price)
        //     {
        //         price -= arr[i];
        //         count.push_back(arr[i]);
        //     }
        //     if (price == 0)
        //     {
        //         break;
        //     }
        // }
        if (arr[i] < price)
        {
            ans += (price / arr[i]);
            price = price % arr[i];
        }
        if (price == 0)
        {
            break;
        }
    }
    cout << ans;
    // for (int i = 0; i < count.size(); i++)
    // {
    //     cout<<count[i]<<",";
    // }
}
void max_profit(vector<int> deadline, vector<int> profit)
{
    vector<pair<int, int>> p{profit.size(), make_pair(0, 0)};
    int maxProfit = 0;
    int safe_deadline;
    for (int i = 0; i < profit.size(); i++)
    {
        p[i] = make_pair(deadline[i], profit[i]);
    }
    sort(p.begin(), p.end(), compare);
    maxProfit = p[0].second;
    safe_deadline = 2;

    for (int i = 1; i < profit.size(); i++)
    {
        if (safe_deadline <= p[i].first)
        {
            maxProfit += p[i].second;
            safe_deadline++;
        }
    }
    cout << maxProfit;
}
class jobs
{
public:
    int index;
    int deadline;
    int profit;

    jobs(int index, int deadline, int profit)
    {
        this->index = index;
        this->deadline = deadline;
        this->profit = profit;
    }
};
void max_profit2(vector<pair<int, int>> a)
{
    vector<jobs> job;//vector of objects!!
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        job.emplace_back(i, a[i].first, a[i].second);
    }
    sort(job.begin(), job.end(), [](jobs &a, jobs &b)
         { return a.profit > b.profit; });

    int maxProfit = job[0].profit;
    int safeDeadline = 2;
    cout << "SEQUENCE : " << job[0].index<< "->";
    for (int i = 1; i < a.size(); i++)
    {
        if (job[i].deadline >= safeDeadline)
        {
            maxProfit += job[i].profit;
            safeDeadline++;
            cout << job[i].index << "->"<<endl;
        }
    }
    cout << "max-profit : " << maxProfit;
}

int main()
{
    vector<int> start = {10, 12, 20};
    vector<int> end = {20, 27, 30};

    vector<int> values = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int knapsack_weight = 50;

    vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 500};

    // JOBS
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 10, 40, 30};

    vector<pair<int, int>> P(profit.size(),make_pair(0,0));
    P[0] = make_pair(deadline[0], profit[0]);
    P[1] = make_pair(deadline[1], profit[1]);
    P[2] = make_pair(deadline[2], profit[2]);
    P[3] = make_pair(deadline[3], profit[3]);

    // activity_selection(start, end);
    // knapsack_problem(values, weight, knapsack_weight);
    // min_absolute_difference(start, end);
    // indian_coins(590, arr);
    // max_profit(deadline, profit);
    max_profit2(P);

    return 0;
}

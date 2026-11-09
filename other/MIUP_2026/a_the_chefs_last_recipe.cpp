#include <bits/stdc++.h>

bool topo_sort(std::string curr, std::unordered_map<std::string, std::vector<std::string>> &graph, std::unordered_map<std::string, int> &colors, std::stack<std::string> &order)
{
    colors[curr] = 1;

    for (int i = 0; i < graph[curr].size(); i++)
    {
        if (!colors.contains(graph[curr][i]))
        {
            if (topo_sort(graph[curr][i], graph, colors, order))
                return true;
        }
        else if (colors[graph[curr][i]] == 1)
            return true;
    }

    order.push(curr);
    colors[curr] = 2;
    return false;
}

void solve()
{
    int n;
    std::cin >> n;

    std::unordered_set<std::string> unique_ingredients;
    std::unordered_map<std::string, std::vector<std::string>> graph;
    for (int i = 0; i < n; i++)
    {
        std::string from;
        std::string discard;
        std::string to;
        std::cin >> from >> discard >> to;
        unique_ingredients.insert(from);
        unique_ingredients.insert(to);
        graph[from].push_back(to);
    }

    std::unordered_map<std::string, int> colors;
    std::stack<std::string> order;
    for (auto it = unique_ingredients.begin(); it != unique_ingredients.end(); it++)
    {
        if (!colors.contains(*it))
            if (topo_sort(*it, graph, colors, order))
            {
                std::cout << "NOT POSSIBLE\n";
                return;
            }
    }

    while (!order.empty())
    {
        std::cout << order.top();
        order.pop();
        if (order.empty())
            std::cout << "\n";
        else
            std::cout << " ";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
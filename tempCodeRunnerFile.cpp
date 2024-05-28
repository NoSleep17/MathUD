
    if (v1.size() != v2.size())
        return 1;
    else
    {
        for (int i = 0; i < n; ++i)
            ans = ans + (v1[i] * v2[i]);
        return ans;
    }
}
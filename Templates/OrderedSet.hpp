#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T, typename compare = less<T>>
using ordered_set =
    tree<K, null_type, compare, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename compare = less_equal<T>>
using ordered_multiset =
    tree<K, null_type, compare, rb_tree_tag, tree_order_statistics_node_update>;

/**
 * order_of_key(x) - Get number of elements strictly less than x
 * find_by_order(x) - Find (x-1)th element from starting int the sorted
 * collection
 */
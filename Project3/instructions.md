# Project 3: Social Network Analysis (SNA)

## Summary

Create a C++ program that will read in the text file containing graph specifications and display the required results after performing operations on the graph. The program should be able to create the directed graph from the input file and output the results according to the *In-Degree of Centrality*.

## Social Network Analysis and Common Metrics

As social networking is very popular among people, there is a huge interest in the study of extracting information from these networks, the so-called social network analysis (SNA). The usage of social network analysis, however, is far beyond that of Facebook or Twitter. The principle of SNA can be applied to other things; such as, finding the source and flow of an infectious disease, and scheduling the optimal production-market distribution for a globalized company.

The basic structure of SNA is a graph. To evaluate the characteristics of a graph and the nodes inside, people gradually develop a set of metrics, some of them are:

## Degree of Centrality

In an undirected graph, the degree centrality of the ith node (denoted by **C_D(i))** is the node degree (number of edges connected to this node), denoted by **deg(i)**.

**C_D(i)** = **deg(i)**

We can interpret this as the ``how connected'' this node is in general sense. In a directed graph, the in-degree of centrality comes in two types: the *in-degree centrality* and the *out-degree centrality*.

- The *in-degree centrality* is number of edges that are coming to the node.
- The *out-degree centrality* uses the number of edges that are coming out of the node.

## Dataset Description: Social network Accounts and their friends

You will be provided with the accounts with their friends and for each friend his/hers friends etc. By using these data, build up a graph and calculate the *In-Degree of Centrality* for each account.

## Input data format

A sample of the input data is:
**
```
github   john_stewart
github   microsoft
microsoft  oracle
```

The two columns are defining the relationship between two accounts. The account in the **second** column is **following** the account in the **first** column. Thus, this is a directed graph. The edge goes from the account in the second column to the account in the first column (second --> first).

## Task Decomposition

## Read in data

The data is in the format of:

```
Name_1   Name_2
Name_x   Name_y
```

For each line there will be two usernames separated by three spaces. Each username is no longer than 15 characters and contain only alphanumeric characters(letters A-Z, a-z, numbers 0-9) with the exception of underscores. For each name, change every UPPERcase to lowercase.

## For you to decide

Define an account class representing each node in the graph. For this class there are some essential concepts that must be captured:

- **name**: store a username
- **followers**: other users following this account
- **following**: other users that this account is following

The created account class objects need to be stored properly. Decide a way to store this list of all users from input data sets; class definitions are up to you, but the fundamental structure will reflect a directed graph with nodes and edges.

Suggestion: use adjacency lists (of input edges and output edges) for each node, rather than a giant adjacency matrix for the entire graph.

## Recommended classes

You may use classes suggested below or create more classes as you see fit (additional files **project3a.h** and **project3a.cpp**, **project3b.h** and **project3b.cpp**, **project3c.h** and **project3c.cpp** are provided if you choose to use them, otherwise, submit the empty files.)

- **Account** - see details above (use one of the provided project3x files (x is a or b or c) to implement this class)
- **Graph** -- abstraction to maintain a list of Vertices and to connect vertices by adding edges. Should have methods to find a vertex (by providing its name), and to add an edge (by providing the src and dst names). Other methods may be useful, and are up to you.

## Calculate the In-Degree Centrality for each node

Calculate the *in-degree centrality* for all accounts. Once the *in-degree centrality* has been calculated for each account we want to find the most connected account in the graph. This should be the account with the largest *in-degree of centrality*. If there is a tie, break it with alphabetical order. Once this account has been found we want to find all of the accounts who are within a depth of 2 from the most connected account (root account) and sort the remaining accounts (excluding the most connected user) alphabetically.

## Find accounts nearby

For the root account (the account with the largest *in-degree centrality*), find all following accounts within the depth of 2 of the root account, regardless of whether they are being followed by that root account. It is okay to have usernames that are duplicate entries, (e.g., alexdownie follows microsoft, and alexdownie follows twitter, and twitter follows microsoft, if the root account is microsoft, alexdownie will show up two times). When exploring, use *in-degree* (not *out-degree*), i.e., look for people following that node.

## Write results to the standard output

The program should output the tree of all accounts within a depth of 2 of the root account. The list should be printed in alphabetical order for each node of the tree (up to depth 2), using a depth-first or breadth-first (your choice) search algorithm to print with the root account (i.e. the most connected account) at the top of the list.

**The list should be printed in alphabetical order for each one of the accounts**. The output written should be in the following format:

```
The root account is Name, with in-degree centrality of N. There are M users in the social network.
username1 (distance1)
username2 (distance2)
```

where Name is the name (as entered in the file), N is the in-degree centrality and M is the number of users in the social network. The users should be sorted alphabetically by name. username1 should be the root user. distance is the depth of that username.

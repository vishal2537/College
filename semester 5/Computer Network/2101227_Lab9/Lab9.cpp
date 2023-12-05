#include<bits/stdc++.h>
using namespace std;

struct RoutingEntry
{
    string net;
    int masklength;
    string nexthop;
    RoutingEntry(string p,int n, string i) : net(p),masklength(n), nexthop(i) {}
};
string hexa_to_binary(string &hexAddress);
string ipv4_to_binary(string &ipAddress);
string conversion_to_binary(string &nett);
string longestPrefixMatch(vector<RoutingEntry> &routingTable, string ipAddress);

int main()
{

    vector<RoutingEntry> routingTable = {
        {"C4.50.0.0",12, "A"},
        {"C4.5E.10.0",20, "B"},
        {"C4.60.0.0",12, "C"},
        {"C4.68.0.0",14, "D"},
        {"80.0.0.0",1, "E"},
        {"40.0.0.0",2, "F"},
        {"00.0.0.0",2, "G"},
    };

    for (auto &i : routingTable)
    {
        i.net = conversion_to_binary(i.net);
    }

    int t;
    cout << "Enter number of input: ";
    cin>>t;
    while(t--)
    {
        string ip_add;
        cout << "Enter the destination IP address: ";
        cin >> ip_add;
        ip_add = conversion_to_binary(ip_add);
        // cout << ip_add << endl;
        string nxthop = longestPrefixMatch(routingTable,ip_add);
        cout <<"Next hop : "<< nxthop << endl;
    }
    return 0;
}

string hexa_to_binary(string &hexAddress)
{
    string binaryIP = "";
    string hexOctet;
    stringstream ss(hexAddress);
    while (getline(ss, hexOctet, '.'))
    {
        int value = stoi(hexOctet, 0, 16);
        bitset<8> bits(value);
        binaryIP += bits.to_string();
    }
    return binaryIP;
}

// string ipv4_to_binary(string &ipAddress)
// {
//     string binaryIP = "";
//     string octet;
//     stringstream ss(ipAddress);
//     while (getline(ss, octet, '.'))
//     {
//         int value = stoi(octet);
//         bitset<8> bits(value);
//         binaryIP += bits.to_string();
//     }

//     return binaryIP;
// }

string conversion_to_binary(string &nett)
{
    // int flag = 0;
    // for (char c : nett)
    // {
    //     if (c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F')
    //     {
    //         flag = 1;
    //         break;
    //     }
    // }

    // if (flag == 1)
    // {
        return hexa_to_binary(nett);
    // }
    // else
    // {
        // return ipv4_to_binary(nett);
    // }
}

string longestPrefixMatch(vector<RoutingEntry> &routingTable, string ipAddress)
{
    string nxthop = "NONE";
    int longest_matched_length = -1;

    for (auto entry : routingTable)
    {
        int temp = 0;
        string x = entry.net;
        for (int i = 0; i < entry.masklength; i++)
        {
            if ((x[i]) == (ipAddress[i]))
            {
                temp++;
            }
            else
            {
                break;
            }
        }
        if (longest_matched_length < temp)
        {
            longest_matched_length = temp;
            nxthop = entry.nexthop;
        }
    }
    return nxthop;
}
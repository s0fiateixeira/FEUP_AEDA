#include <iostream>
#include <vector>

using namespace std;

template <class N, class E> class Edge;

// exception NodeAlreadyExists
template <class N>
class NodeAlreadyExists
{
public:
    N info;
    NodeAlreadyExists(N inf) { info=inf; }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NodeAlreadyExists<N> &no)
{ out << "Node already exists: " << no.info; return out; }


// exception NodeDoesNotExist
template <class N>
class NodeDoesNotExist {
public:
    N info;
    NodeDoesNotExist(N inf) {
        info = inf;
    }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NodeDoesNotExist<N> &no)
{ out << "Node does not exist: " << no.info; return out; }

// exception EdgeAlreadyExists
template <class N>
class EdgeAlreadyExists
{
public:
    N beg, end;
    EdgeAlreadyExists(N beg, N end): beg(beg), end(end) {}
};
template <class N>
std::ostream & operator<<(std::ostream &out, const EdgeAlreadyExists<N> &no)
{ out << "Edge already exists: " << no.beg << " , " << no.end; return out; }

// exception EdgeDoesNotExist
template <class N>
class EdgeDoesNotExist {
public:
    N beg, end;
    EdgeDoesNotExist(N beg, N end): beg(beg), end(end) {}
};
template <class N>
std::ostream & operator<<(std::ostream &out, const EdgeDoesNotExist<N> &no)
{ out << "Edge does not exist: " << no.beg << " , " << no.end; return out; }


template <class N, class E>
class Node {
public:
    N info;
    vector< Edge<N,E> > edges;
    Node(N inf) {
        info = inf;
    }
};

template <class N, class E>
class Edge {
public:
    E value;
    Node<N,E> *destination;
    Edge(Node<N,E> *dest, E val) {
        value = val;
        destination = dest;
    }
};

template <class N, class E>
class Graph {
    vector< Node<N,E> *> nodes;
public:
    Graph(){};
    ~Graph(){};
    unsigned numEdges() const
    {
        int result = 0;
        for (int i = 0; i < nodes.size(); i++)
        {
            result += nodes[i]->edges.size();
        }
        return (result);
    };
    unsigned numNodes() const {return (nodes.size());};
    Graph & addNode(const N &inf)
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i]->info == inf)
            {
                throw NodeAlreadyExists<N>(inf);
            }
        }
        nodes.push_back(new Node<N,E>(inf));
        return(*this);
    };
    Graph & addEdge(const N &begin, const N &end, const E &val)
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i]->info == begin)
            {
                for (int j = 0; j < nodes[i]->edges.size(); j++)
                {
                    if (nodes[i]->edges[j].destination->info == end)
                    {
                        throw EdgeAlreadyExists<N>(begin, end);
                    }
                }
                for (int k = 0; k < nodes.size(); k++)
                {
                    if (nodes[k]->info == end)
                    {
                        nodes[i]->edges.push_back(Edge<N,E> (nodes[k], val));
                        return(*this);
                    }
                }
                throw NodeDoesNotExist<N>(end);
            }
        }
        throw NodeDoesNotExist<N>(begin);
    };
    E & edgeValue(const N &begin, const N &end)
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i]-> info == begin)
            {
                for (int j = 0; j < nodes[i]->edges.size(); j++)
                {
                    if (nodes[i]->edges[j].destination->info == end)
                    {
                        return(nodes[i]->edges[j].value);
                    }
                }
                throw EdgeDoesNotExist<N>(begin, end);
            }
        }
        throw NodeDoesNotExist<N>(begin);
    };
    Graph & removeEdge(const N &begin, const N &end)
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i]->info == begin)
            {
                for (auto j = nodes[i]->edges.begin(); j != nodes[i]->edges.end(); j++)
                {
                    if ((*j).destination->info == end)
                    {
                        nodes[i]->edges.erase(j);
                        return(*this);
                    }
                }
                throw EdgeDoesNotExist<N>(begin, end);
            }
        }
        throw NodeDoesNotExist<N>(begin);
    };
    void print(std::ostream &os) const
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            os << "( " << nodes[i]->info;
            for (int j = 0; j < nodes[i]->edges.size(); j++)
            {
                os << "[ " << nodes[i]->edges[j].destination->info << " " << nodes[i]->edges[j].value << "] ";
            }
            os << ") ";
        }
    };


};

template <class N, class E>
std::ostream & operator<<(std::ostream &out, const Graph<N,E> &g)
{
    g.print(out);
    return out;
};



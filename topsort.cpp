#include <unordered_map> 

class node 
{
    public:
        vector<int> neighbors;
        bool visited;
        int no;
};


class Solution 
{
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
        {

            courses = new node[numCourses]; 

            for (vector<int> edge :prerequisites)
            {
                courses[edge[1]].neighbors.push_back(edge[0]);
            }

            for (int i = 0; i < numCourses; i++)
            {
                courses[i].visited = false;
                courses[i].no = i;
            }

            vector<int> * out = new vector<int>();

            stack<int> s;
            for (int i = 0; i < numCourses; i++)
            {
                if (!courses[i].visited)
                {
                    // map for keeping the stack of the nodes
                    // if dfs finds a neighbor which is already in stack
                    // we find a backedge aka cycle => course schedule wont work

                    unordered_map<int, bool> umap;
                    if ((dfs(&courses[i], s, umap)) <0)
                    {
                        return *out;
                    }
                }
            }

            stack_to_vector(s, *out);
            return *out;
        }


        ~Solution()
        {
            delete[] courses;
        }

    private:
        node * courses;

        int dfs(node * course, stack<int>& s, unordered_map<int, bool>& umap)
        {
            course->visited = true;
            umap[course->no] = true;

            for (std::vector<int>::iterator it = course->neighbors.begin() ; 
                    it != course->neighbors.end(); 
                    ++it)
            {
                std::unordered_map<int, bool>::iterator it2;
                // we found a neighbor in the stack
                // so we have a problem of back edge aka cycle
                if ((it2 = umap.find((courses[(*it)].no))) != umap.end())
                {
                    return -1;
                }

                if (courses[*it].visited == false)
                {
                    if (dfs(&courses[*it], s, umap) < 0)
                    {
                        return -1;
                    }
                }
            }

            umap.erase(course->no);
            s.push(course->no);
            return 0;
        }

        void stack_to_vector(stack<int> &s, vector<int> &v)
        {
            while (!s.empty())
            {
                v.push_back(s.top());
                s.pop();
            }
        }
};







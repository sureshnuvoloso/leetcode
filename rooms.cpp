
void main()
{

   
    
    vector<int> *ivl = new vector<int>();
    vector<<vector<int>> intervals;
    *ivl[0]= 5;
    *ivl[1] = 30;
    intervals.push_back(*ivl);
}

    
    Solution sln;


bool cmp(vector<int> ivl1 , vector<int> ivl2)
{
    return (ivl1[0] < ivl2[0]);
}
class Solution {
    public:
        int minMeetingRooms(vector<vector<int>>& intervals) {

            if (intervals.size() == 0)
            {
                return 0;
            }

            if (intervals.size() == 1)
            {
                return 1;
            }

            int cnt = 1;

            std::sort(intervals.begin(), intervals.end(), cmp);

            std::priority_queue<int> pq;
            pq.emplace(intervals[0][1]);

            for (auto it = begin (intervals) + 1; it != end (intervals); ++it) 
            {
                vector<int> ivl = *it;

                if (ivl[0] > pq.top())
                {
                    //we dont need a room and we could use the top guys room
                    pq.pop();

                }
                else
                {
                    // we need a room, so increase teh cnt;
                    cnt++;
                }

                pq.emplace(ivl[1]);            
            }

            return cnt;


        }
};


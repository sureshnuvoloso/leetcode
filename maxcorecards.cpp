

/*
https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
*/

class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k)
    {
        return (maxScore_helper(cardPoints, 0, cardPoints.size() -1 , k));
        
    }
    
    
    
    int maxScore_helper(vector<int>& cardPoints, int start_index, int end_index, int k) {
          if ( k == 0 ){ return 0;}
        
        #if 0
        if ( (end_index - start_index + 1 ) == k )
        {
            return sum(cardPoints, start_index, end_index);
        }
        #endif 
        
        return std::max( (cardPoints[end_index] +  maxScore_helper(cardPoints, start_index, end_index -1, k -1 )) ,
                      
                    (cardPoints[start_index] + maxScore_helper(cardPoints , start_index + 1 , end_index, k -1) ));       
                   
        
    }
    
    #if 0
    
    private :
    int sum(vector<int>& cardPoints, int start_index, int end_index) 
    {
        int sum = 0;
        
        for (int i = start_index; i< end_index +1 ; i++)
        {
            sum +=cardPoints[i];
        }
        
        return sum;
    }
    #endif 

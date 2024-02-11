class Solution {
public:
// AT PARTICULAR INSTANCE WE  TAKE GREATEST 2 ELEMENT AND DECRESE ITS VALUE BY 1 AND AGAIN PUSHED IN THE QUEUE
// THEREFORE IF THE SIZE OF QUEUE IS 1 THEN WE CANT TAKE OUT TWO ELEMENT THEREFORE WE HAVE TO RUN THE LOOP TILL
// SIZE IS GREATER THAN 2. AFTER DECREASING IF THE VALUE IS EQUAL TO ZERO THEN WE WILL NOT PUSH IN THE QUEUE
// ALL THOUGH THE NUMBER OF WATER IS COMPLETED. 
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        for(int i=0;i<3;i++)
        {
            if(amount[i]!=0) // [5,0,0,] TO AVOID THIS TYPE OF CASES. IF WE DONOT DO THIS STEP THEN SIZE OF 
            pq.push(amount[i]);// QUEUE IS 3 THEN THE LOOP HAS BEEN STARTED AND AFTER TAKING TWO VALUE AND 
        }               // DECREASED THAT VALUE WE GET (4,-1) AND THEN INSERTED IN QUEUE THEN THE DECRESED VALUE 
        int count=0; // WILL NEVER BE ZERO AND HENCE THE SIZE WILL NOT DECREASES ....INFINTE LOOP OCCUR
        while(pq.size()>1)
        {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            top1-=1;
            top2-=1;
            if(top1!=0)
            pq.push(top1);
            if(top2!=0)
            pq.push(top2);
            count++; 
        }
        if(!pq.empty()) return count+pq.top();
        return count;


    }
};
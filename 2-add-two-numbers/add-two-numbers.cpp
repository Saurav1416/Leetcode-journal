/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // int extract(ListNode* l, int mul){
    //     int sum =0;
    //     while( l){
    //         sum+= l->val * mul;
    //         mul*=10;
    //         l=l->next;
    //     }
        

    //     return sum;
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    //     int no1= extract( l1,1);
    //     int no2 = extract( l2,1);

    //     int sum = no1+no2;
    //    ListNode * dummy = new ListNode( 0);
    //    ListNode * temp = dummy;
    //     while( sum>0){

    //         int rem = sum %10;
    //         ListNode * a = new ListNode(rem);
    //         temp->next =a ;
    //         temp = temp->next;
    //         sum = sum/10;

    //     }
        

    //     return dummy->next;  this method wont work cuz sum is too big not even long long can handle it 



       int length1=0;
      ListNode * head1 = l1;
      while( head1){
        length1 ++;
        head1= head1->next;

      }
      int length2=0;
      ListNode * head2 = l2;
      while( head2){
        length2 ++;
        head2= head2->next;

      }
      if( length1 < length2){
         swap(length1,length2);
      }




    ListNode * dummy = new ListNode ( 0);
        int carry = 0;
        ListNode * temp = dummy;
       

        while( length1>0 || carry){

        ListNode * a = new ListNode( 0 );
        int l11=0;;
        int l22=0;
        if( l1){
           l11 =l1->val;
            l1=l1->next;
        }
        if( l2){
            l22 = l2->val;
            l2= l2->next;
        }
           int sum = l11 +l22 + carry ;
            if( sum > 9){
                a->val=  sum%10;
                carry = sum/10;
            }else{
                a->val =  sum;
                carry =0;

            }

            temp->next = a ;
            temp = temp->next;
            length1--;
            

        }
        return dummy->next;






      
    }
};




























import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
   //heap에 저장할 노드 클래스 만들기 
   //노드 클래스는 stage 숫자랑 그 해당 스테이지의 실패율을 저장합니다
  
  public static class Node implements Comparable<Node>
	{
		double failureRate;
		int stage;     
		
		public Node(int stageNum, double failure)
		{
			stage = stageNum;
			failureRate = failure;
		}
		
    //heap이 어떤 논리로 노드를 비교할건지
    //otherNode의 failureRate가 더 크면 -1리턴, 아니면 1 리턴
    //하지만 failure rate가 같다면, stage가 더 작으면 양수를 리턴합니다. (stage 수가 더 작을수록 크다는 뜻) 
    
		public int compareTo(Node otherNode)
		{
			if(this.failureRate > otherNode.failureRate)
				return 1;
			else if(this.failureRate < otherNode.failureRate)
				return -1;
			else {
				return otherNode.stage - stage;
			}
		}
	}
  
   public int[] solution(int N, int[] stages) {
        int[] answer = new int[N];
        int[] stagesSum = new int[N + 2];   //각 stages들의 도전자 수 
        Arrays.fill(stagesSum, 0);          //stagesSum을 0으로 채운다
        
        PriorityQueue<Node> nodeQueue = new PriorityQueue<Node>();  //사용할 heap을 initialize
        
        for(int stage: stages)
        {
        	stagesSum[stage] = stagesSum[stage] + 1;                    //각 stages들의 도전자 수 저장
        }
        
     
        int countSuc = stagesSum[stagesSum.length - 1];     //성공한 개수를 나타낸다. stages들의 도전자 수를 뒤에서 부터 count하면된다.
        for(int i = stagesSum.length - 2; i > 0 ; i--)
        {
        	countSuc = countSuc + stagesSum[i];
        	double failureRate;
        	if(countSuc == 0)
        	{
        		failureRate = 0;                        //성공한 사람이나 도전자가 없으면 0
        	}
        	else
        	{
        		failureRate = (double) stagesSum[i] / countSuc;
        	}
        	nodeQueue.add(new Node(i, failureRate));       //heap에 노드를 넣어서 nlog(n)시간으로 정렬한다.  
        }
        
        for(int i = answer.length - 1; i > -1 ; i--)
        {
        	answer[i] = nodeQueue.element().stage;         //heap에 있는 노드를 뺀다(nlog(n)) 
        	nodeQueue.remove();
         }
        
        
        return answer;
        
    }
}

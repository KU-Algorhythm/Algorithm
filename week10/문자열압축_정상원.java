class Solution {
    public int solution(String s) {
      
         int min = s.length();

        //모든 len길이를 테스트 합니다. len은 반을 넘을 필요가 없으므로 s.length() / 2 + 1 까지만
      
        for( int len = 1 ; len < s.length() / 2 + 1 ; len++ )
        {
            //StringBuilder를 사용해서 매번 새로운 string을 만들지 않습니다.
          
            StringBuilder stringBuilder = new StringBuilder(s.length());
            
            
            String curStr = s.substring(0, len);
            int curTimes = 1;
            int i;

            for(i = len; i < s.length() - len + 1; i = i + len)
            {
                String tempStr = s.substring(i, i + len);
                if(curStr.equals(tempStr))
                {
                    curTimes++;
                }
                else
                {
                    if(curTimes > 1)
                    {
                        stringBuilder.append(curTimes);
                    }

                    stringBuilder.append(curStr);
                    curTimes = 1;
                    curStr = tempStr;
                }
            }

            if(curTimes > 1)
            {
                stringBuilder.append(curTimes);
            }

            stringBuilder.append(curStr);
            stringBuilder.append(s.substring(i));

            String tempString = stringBuilder.toString();
            if(tempString.length() < min)
            {
                min = tempString.length();
            }

        }

        return min;
    }
}

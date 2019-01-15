/*libresistance.c beräkna ersättningsresistansen*/
float calc_resistance(int count, char conn, float *array){
        /*kolla nollpekare*/
        if(!array){
                return -1;
        }
        float sum=0;
        if (conn=='S'){
                /*seriel*/
                for(int i=0; i<count;i++){
                        sum+=array[i];
                }
        }else if(conn=='P'){
                /*parallell*/

                for (int i=0; i<count; i++){
                        /*kontrollera så att ingen är noll vid parallell*/
						if(array[i]==0)
                                return -1;
                        sum+=1/array[i];
                }
                sum=1/sum;
        }else{
                /*varken S || P*/
                return -1;
        }
        return sum;
}


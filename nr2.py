import sys
OPPONENT_ROCK="A"
OPPONENT_PAPER="B"
OPPONENT_SCISSOR="C"

ME_ROCK="X"
ME_PAPER="Y"
ME_SCISSOR="Z"
good={
   OPPONENT_ROCK:ME_SCISSOR,
  OPPONENT_PAPER:ME_ROCK,
  OPPONENT_SCISSOR:ME_PAPER

}
bad={
 OPPONENT_ROCK:ME_PAPER,
  OPPONENT_PAPER:ME_SCISSOR,
  OPPONENT_SCISSOR:ME_ROCK 
}
tie={
 OPPONENT_ROCK:ME_ROCK,
  OPPONENT_PAPER:ME_PAPER,
  OPPONENT_SCISSOR:ME_SCISSOR 
}

me_score={
    ME_ROCK:1,
    ME_PAPER:2,
    ME_SCISSOR:3
}
WIN_SCORE=6
TIE_SCORE=3
LOST_SCORE=0

def load_input(path:str):
    result=[]
    with open(path) as f:
        for line in f:
            result.append(line.split())
    return result
    print(result)
def get_score(opponent,me):
    if good[opponent]==me:
        return me_score[me]+LOST_SCORE
    elif tie[opponent]==me:
        return me_score[me]+TIE_SCORE
    elif bad[opponent]==me:
        return me_score[me]+WIN_SCORE
    
result=load_input(sys.argv[1])
s=0
for move in result:
    s+=get_score(*move)
print(s)


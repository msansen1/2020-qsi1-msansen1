type player =
  | PlayerOne
  | PlayerTwo;

type point =
  | Love
  | Fifteen
  | Thirty;

type pointsData = {
  playerOne: point,
  playerTwo: point
};

type fortyData = {
  player: player, /* The player who have forty points */
  otherPlayerPoint: point
};

let fd : fortyData = {player: PlayerOne, otherPlayerPoint: Love};

type score =
  | Points(pointsData)
  | Forty(fortyData)
  | Deuce
  | Advantage(player)
  | Game(player);
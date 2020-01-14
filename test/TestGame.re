open Framework;
open TennisKata.Game;

describe("Test Game transitions", ({test}) => {
  test("Given PlayerOne then PlayerTwo is different", ({expect}) => {
    expect.notEqual(PlayerOne, PlayerTwo)
  });

  test("Given deuce when PlayerOne wins then score is correct", ({expect}) => {
    expect.equal(scoreWhenDeuce(PlayerOne), Advantage(PlayerOne))
  });

  test("Given deuce when PlayerTwo wins then score is correct", ({expect}) => {
    expect.equal(scoreWhenDeuce(PlayerTwo), Advantage(PlayerTwo))
  });

  test(
    "Given advantage when advantaged player wins then score is correct",
    ({expect}) => {
    let advantagedPlayer = PlayerOne;
    let winner = advantagedPlayer;
    expect.equal(
      scoreWhenAdvantage(advantagedPlayer, winner),
      Game(advantagedPlayer),
    );
  });

  test("Given advantage when the other player wins then score is Deuce",
  ({expect}) => {
    let advantagedPlayer = PlayerOne;
    let winner = other(advantagedPlayer);
    expect.equal(
      scoreWhenAdvantage(advantagedPlayer, winner),
      Deuce,
      );
    });

  test(
    "Given player: 40 when wins then score is Game for this player",
    ({expect}) => {
    let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
    expect.equal(
      scoreWhenForty(fortyThirty, fortyThirty.player),
      Game(fortyThirty.player)
    );
  });

  test(
    "Given player: 40 | other : 30 when other wins then score is Deuce",
    ({expect}) => {
    let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
    expect.equal(
      scoreWhenForty(fortyThirty, other(fortyThirty.player)),
      Deuce
    );
  });

  test("Given player: 40 | other : 0 when other wins then score is fortyFifteen",
  ({expect}) => {
    let fortyLove = {player: PlayerOne, otherPlayerPoint: Love};
    let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
    expect.equal(
      scoreWhenForty(fortyLove, other(fortyLove.player)),
      Forty(fortyFifteen)
    );
  });

  test(
    "Given player: 15 | other : 15 when player wins then score is 30/15",
    ({expect}) => {
    let fifteenFifteen = {playerOne: Fifteen, playerTwo: Fifteen};
    let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
    expect.equal(
      scoreWhenPoints(fifteenFifteen, PlayerOne),
      Points(thirtyFifteen)
    );
  });

  test("Given player: 0 | other : 15 when other wins then score is 0/30",
  ({expect}) => {
    let zeroFifteen = {playerOne: Love, playerTwo: Fifteen};
    let zerothirty = {playerOne: Love, playerTwo: Thirty};
    expect.equal(
      scoreWhenPoints(zeroFifteen, PlayerTwo),
      Points(zerothirty)
    );
  });

  test(
    "Given player: 30 | other : 15 when player wins then score is 40/15",
    ({expect}) => {
      let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
      let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
      expect.equal(
        scoreWhenPoints(thirtyFifteen, PlayerOne),
        Forty(fortyFifteen)
    );
  });

  test(
    "Player to string",
    ({expect}) => {
      expect.equal( string_of_player(PlayerOne),"Player One");
      expect.equal( string_of_player(PlayerTwo),"Player Two");
  });

  test(
    "Point to string",
    ({expect}) => {
      expect.equal(string_of_point(Love),"0");
      expect.equal(string_of_point(Fifteen),"15");
      expect.equal(string_of_point(Thirty),"30");
  });

  test(
    "Point to string",
    ({expect}) => {
      /*Test d'un score simple*/
      let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
      expect.equal(string_of_score(Points(thirtyFifteen)),"30/15");
      /*Test d'un score forty*/
      let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
      expect.equal(string_of_score(Forty(fortyFifteen)),  "40/15");
      /*Test d'un score Deuce*/
      expect.equal(string_of_score(Deuce),  "40a");
      /*Test d'un score Advantage*/
      expect.equal(string_of_score(Advantage(PlayerOne)),  "advantage in Player One");
      /*Test d'un score Jeu*/
      expect.equal(string_of_score(Game(PlayerOne)),  "Game for Player One");
      expect.equal(string_of_score(Game(PlayerTwo)),  "Game for Player Two");
  });

});

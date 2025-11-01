from random import choice
ITEM_LIST = ("BOMB")

class Game :

    class GameLogic :
        def BOMB(Game, player1, player2):
            player2.free_flag = False
            player2.free_count += 1

    # class stores question
    class QuestionSRC :

        # contain name answer weight
        class Question :
            name = None
            text = None
            answer = None
            options = None
            #weight = None
            def __init__(self, _name, _text, _answer, _options, _weight=0):
                self.name = _name
                self.text = _text
                self.answer = _answer
                self._options = _options
            #    self.weight = _weight


        name = None

        question_pile = None
        question_num = 0
        question_striked = 0

        def __init__(self, _name, _question_pile, _question_num ):
            self.name = _name
            self.question_pile = _question_pile
            self.question_num = _question_num


    class Player :
        name = ""
        end_flag = False
        free_flag = True

        free_count = 0

        right_count = 0
        false_count = 0

        def __init__(self,_name):
            self.name = _name


    name        = None
    end_flag    = False
    players     = None          # player list

    question_src = None     # QustionSRC

    def nextTurn(self):

    def __init__(self, _name, _question_src, _players):
        self.name = _name
        self.question_src = _question_src
        self.players = _players

if __name__ == "__main__" :
    def test_objects_creation():
        test_object_Player = Game.Player( "test_player" )
        print("Player object creat")
        test_object_Question = Game.QuestionSRC.Question("test_question", "test_question_text", 0, ("test_question_option1","test_question_option2"))
        print("Question object creat")
        test_object_QuestionSRC = Game.QuestionSRC("test_questionSRC", (test_object_Question), 1)
        print("QuestionSRC object creat")

        test_object_Game = Game("test_game", test_object_QuestionSRC, (test_object_Player))
        print("Game object creat")

if __name__ == "__main__" :
    print("GAME MAIN IN")
    
    test_objects_creation()

    print("GAME MAIN OUT")

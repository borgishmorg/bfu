.PHONY: all exe clean screen logic items weapons potions scrolls marvel others

ITEMS_INC=-I"include/logic/items/" -I"include/logic/items/potions/" -I"include/logic/items/weapons/" -I"include/logic/items/others/" -I"include/logic/items/scrolls/" -I"include/logic/items/marvel/"
SCREEN_INC=-I"include/screen/" -I"include/screen/screen elements/"
LOGIC_INC=-I"include/logic/"
UTILITIES_INC=-I"include/utilities/" 
INC=-I"include/" $(ITEMS_INC) $(SCREEN_INC) $(LOGIC_INC) $(UTILITIES_INC)

all: screen logic items utilities exe
	
exe:
	g++ -std=c++14 $(INC) -o "obj/Game.o" -c "src/Game.cpp" 
	g++ -std=c++14 $(INC) -o "obj/Main.o" -c "src/Main.cpp" 
	g++ -std=c++14 -o BattleRoyale.exe obj/*.o
screen: obj
	g++ -std=c++14 $(INC) -o "obj/Screen.o" -c "src/screen/Screen.cpp" 
	g++ -std=c++14 $(INC) -o "obj/GameScreen.o" -c "src/screen/GameScreen.cpp" 
	g++ -std=c++14 $(INC) -o "obj/ScreenElement.o" -c "src/screen/screen elements/ScreenElement.cpp" 
	g++ -std=c++14 $(INC) -o "obj/MapScreenElement.o" -c "src/screen/screen elements/MapScreenElement.cpp" 
	g++ -std=c++14 $(INC) -o "obj/PlayerScreenElement.o" -c "src/screen/screen elements/PlayerScreenElement.cpp" 
	g++ -std=c++14 $(INC) -o "obj/MessageScreenElement.o" -c "src/screen/screen elements/MessageScreenElement.cpp" 
logic: obj
	g++ -std=c++14 $(INC) -o "obj/Cell.o" -c "src/logic/Cell.cpp" 
	g++ -std=c++14 $(INC) -o "obj/Map.o" -c "src/logic/Map.cpp" 
	g++ -std=c++14 $(INC) -o "obj/Player.o" -c "src/logic/Player.cpp"
items: obj weapons potions scrolls others marvel
	g++ -std=c++14 $(INC) -o "obj/Item.o" -c "src/logic/items/Item.cpp" 
weapons: obj
	g++ -std=c++14 $(INC) -o "obj/Weapon.o" -c "src/logic/items/weapons/Weapon.cpp" 
	g++ -std=c++14 $(INC) -o "obj/Bow.o" -c "src/logic/items/weapons/Bow.cpp" 
	g++ -std=c++14 $(INC) -o "obj/Sword.o" -c "src/logic/items/weapons/Sword.cpp" 
	g++ -std=c++14 $(INC) -o "obj/AK-47.o" -c "src/logic/items/weapons/AK-47.cpp"
	g++ -std=c++14 $(INC) -o "obj/GrenadeLauncher.o" -c "src/logic/items/weapons/GrenadeLauncher.cpp" 
	g++ -std=c++14 $(INC) -o "obj/SniperRifle.o" -c "src/logic/items/weapons/SniperRifle.cpp" 
	g++ -std=c++14 $(INC) -o "obj/Stone.o" -c "src/logic/items/weapons/Stone.cpp"
potions: obj
	g++ -std=c++14 $(INC) -o "obj/Potion.o" -c "src/logic/items/potions/Potion.cpp" 
	g++ -std=c++14 $(INC) -o "obj/PotionOfHealth.o" -c "src/logic/items/potions/PotionOfHealth.cpp" 
	g++ -std=c++14 $(INC) -o "obj/PotionOfCheerfulness.o" -c "src/logic/items/potions/PotionOfCheerfulness.cpp"
scrolls: obj
	g++ -std=c++14 $(INC) -o "obj/Scroll.o" -c "src/logic/items/scrolls/Scroll.cpp"
	g++ -std=c++14 $(INC) -o "obj/ScrollOfWall.o" -c "src/logic/items/scrolls/ScrollOfWall.cpp"
	g++ -std=c++14 $(INC) -o "obj/ScrollOfClumsiness.o" -c "src/logic/items/scrolls/ScrollOfClumsiness.cpp"
marvel: obj
	g++ -std=c++14 $(INC) -o "obj/InfinityStone.o" -c "src/logic/items/marvel/InfinityStone.cpp"
	g++ -std=c++14 $(INC) -o "obj/InfinityGauntlet.o" -c "src/logic/items/marvel/InfinityGauntlet.cpp"
others: obj
	g++ -std=c++14 $(INC) -o "obj/Label.o" -c "src/logic/items/others/Label.cpp" 
	g++ -std=c++14 $(INC) -o "obj/GPS.o" -c "src/logic/items/others/GPS.cpp" 
	g++ -std=c++14 $(INC) -o "obj/Apple.o" -c "src/logic/items/others/Apple.cpp" 
	g++ -std=c++14 $(INC) -o "obj/Backpack.o" -c "src/logic/items/others/Backpack.cpp" 
	g++ -std=c++14 $(INC) -o "obj/ThirdLeg.o" -c "src/logic/items/others/ThirdLeg.cpp"
utilities: obj
	g++ -std=c++14 $(UTILITIES_INC) -o "obj/CharMatrix.o" -c "src/utilities/CharMatrix.cpp"
obj:
	mkdir obj
clean:
	rm -r ./obj
	rm BattleRoyale.exe
	
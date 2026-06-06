#include <iostream>
#include <string>
#include <print>
#include <cstdlib>
#include <ctime> 

using namespace std;

int main() {
	string nome_personagem;
    
    println("digite o nome do seu personagem");
    cin >> nome_personagem;
	
    srand(time(0));
    
    
    int hp_monstro = 600;
    int hp_heroi = 250;
    int pocao = 3;
    int turno = 1;
    
    println("\nUm Boss com {} de HP apareceu! O combate começou!", hp_monstro);
    println("\nsua vida e {}", hp_heroi);
    system("pause");
    
    while (hp_monstro > 0 && hp_heroi > 0) {
        println("\n[TURNO {}]", turno);
        
        int ataque_base = 65;
        int ataque_monstro = 50;
        int sorte_boss = (rand() % 100) + 1;
        int dado_sorte = (rand() % 100) + 1;
        
        if (dado_sorte > 50) {
            ataque_base = ataque_base * 2;
            println("CRÍTICO! O número da sorte foi {}! {} causou {} de dano!", dado_sorte, nome_personagem, ataque_base);
        } else {
            println("️Ataque normal! O número da sorte foi {}. {} causou {} de dano.", dado_sorte, nome_personagem, ataque_base);
        }
      
        hp_monstro = hp_monstro - ataque_base;
        
        if (sorte_boss > 50 ) {
			ataque_monstro = ataque_monstro * 2;
			println("CRÍTICO! O número da sorte foi {}! monstro causou {} de dano!", sorte_boss, ataque_monstro);
		}	
		 else {
            println("Ataque normal! O número da sorte foi {}. monstro causou {} de dano.", sorte_boss, ataque_monstro);
        }
        
        hp_heroi = hp_heroi - ataque_monstro;
        
        if (hp_heroi <= 125 && pocao > 0) {
			hp_heroi = hp_heroi + 80;
			pocao = pocao - 1;
			println("{} se curou 80 de hp vida atual {} pocao atual {}", nome_personagem, hp_heroi, pocao);
		}
		if (pocao <= 0) {
			println("suas pocoo acabaram {}", pocao);	
		}
		if (pocao < 0) {
			pocao = 0;
		}		
     
        if (hp_monstro < 0) {
            hp_monstro = 0;
        }
        if (hp_heroi < 0) {
			hp_heroi = 0;
		}	
        println("Vida restante do Boss: {}", hp_monstro);
        println("Vida restante de {}: {}", nome_personagem, hp_heroi);
        
        turno = turno + 1;
        
        system("pause");
        
       
    }
    if (hp_monstro == 0 && hp_heroi > 0) {
		println("\nPARABÉNS! O Boss foi destruído em {} turnos!", turno - 1);
	}
	else if (hp_monstro == 0 && hp_heroi == 0) {
		println("\n empate os dois acabou morrendo terminou em {} turnos", turno - 1);
	}
	else {
		println("\n voce perdeu tente denovo morreu em {} turnos", turno - 1);
	}
		
    system("pause");
    return 0;
}

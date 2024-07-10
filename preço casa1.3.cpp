#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

int main()
{ // inicio
	setlocale (LC_ALL, "portuguese");
	
	printf("ATENÇÃO ESTE SOFTWARE É CAPAZ DE FAZER OS CALCULOS APENAS DE CASAS QUADRADAS OU RETANGULARES\n");
	printf("O SOFTWARE FOI PROJETADO PARA LINGUA PORTUGUESA, ENTÃO QUANDO INSERIR NUMEROS QUEBRADOS USE VIRGULA '',''\n\n");
	
	float precoTotal=0;
	bool menu=true;
	
	// valor do terreno
	float larguraTerreno=0, comprimentoTerreno=0, metragemTerreno=0, valorMetroQuadrado=0, precoTerreno=0;
	
	while(menu)
	{
		printf("insira a largura do terreno (em metros): ");
		scanf("%f", &larguraTerreno);
		printf("insira o comprimento do terreno (em metros): ");
		scanf("%f", &comprimentoTerreno);
	
		if((larguraTerreno>0) && (comprimentoTerreno>0))
		{
			menu=false;
			metragemTerreno=larguraTerreno*comprimentoTerreno;
		
			printf("insira a valor do metro quadrado: R$");
			scanf("%f", &valorMetroQuadrado);
		
			precoTerreno=metragemTerreno*valorMetroQuadrado;
			precoTotal=precoTerreno;
			system("cls");
		}
		else
		{
			printf("\n\na largura e o comprimento devem ser maiores que 0!\n\n");
		}
	}
	menu=true;
	
	// limpesa do terreno
	int escolhaLimpeza=0;
	float valorMetroLimpeza=0, precoLimpeza=0;
	
	while(menu)
	{
		printf("o terreno precisa ser limpo?\n[1] SIM\n[2] NÃO\n sua escolha: ");
		scanf("%i", &escolhaLimpeza);
		if(escolhaLimpeza==1)
		{
			menu=false;
			printf("insira o preço da limpeza por metro quadrado: R$");
			scanf("%f", &valorMetroLimpeza);
			precoLimpeza=metragemTerreno*valorMetroLimpeza;
			precoTotal=precoTotal+precoLimpeza;
		}
		else if(escolhaLimpeza==2)
		{
			menu=false;
		}
		else
		{
			printf("\n\nescolha invalida!\n\n");
		}
	}
	menu=true;
	system("cls");
	
	// terraplanagem do terreno
	int escolhaTerraplanagem=0;
	float valorMetroTerraplanagem=0, precoTerraplanagem=0;
	
	while(menu)
	{
		printf("o terreno precisa ser terraplanado?\n[1] SIM\n[2] NÃO\n sua escolha: ");
		scanf("%i", &escolhaTerraplanagem);
		if(escolhaTerraplanagem==1)
		{
			menu=false;
			printf("insira o preço da terraplanegem por metro quadrado: R$");
			scanf("%f", &valorMetroTerraplanagem);
			precoTerraplanagem=metragemTerreno*valorMetroTerraplanagem;
			precoTotal=precoTotal+precoTerraplanagem;
		}
		else if(escolhaTerraplanagem==2)
		{
			menu=false;
		}
		else
		{
			printf("\n\nescolha invalida!\n\n");
		}
	}
	menu=true;
	system("cls");
	
	
	// area da casa
	float larguraCasa=0, comprimentoCasa=0, areaCasa=0, metroFundacao=0;
	
	while(menu)
	{
		printf("insira a largura da casa (em metros): ");
		scanf("%f", &larguraCasa);
		printf("insira o comprimento da casa (em metros): ");
		scanf("%f", &comprimentoCasa);
		areaCasa=larguraCasa*comprimentoCasa;
		if((larguraCasa<=larguraTerreno) && (comprimentoCasa<=comprimentoTerreno) && (larguraCasa>0) && (comprimentoCasa>0))
		{
			menu=false;
		}
		else
		{
			printf("\n\nas medidas da casa não podem ser maiores que as medidas do terreno!\na largura e o comprimento da casa devem ser maiores que 0!\n\n");
		}
	}
	menu=true;
	printf("qual o preço de fundação por m²: R$");
	scanf("%f", &metroFundacao);
	precoTotal=precoTotal+(metroFundacao*areaCasa);
	system("cls");
	
	// calculo telhado
	int escolhaTelhado=0;
	float unidadesTelhado=0, precoTelhado=0, comprimentoNovoMaterialTelhado=0, larguraNovoMaterialTelhado=0, precoNovoMaterialTelhado=0;
	
	while(menu)
	{
		printf("qual o material do telhado?\n[1] telha colonial pvc laranja(R$260)(5,25m x 0,88m)\n[2] telha ondulada brasilit cinza(R$68,90)(1,22m x 1,10m)\n[3] outro material\nsua escolha: ");
		scanf("%i", &escolhaTelhado);
		if(escolhaTelhado==1)
		{
			menu=false;
			unidadesTelhado=areaCasa/(5.25*0.88);
			precoTelhado=unidadesTelhado*260;
			precoTotal=precoTotal+precoTelhado;
		}
		else if(escolhaTelhado==2)
		{
			menu=false;
			unidadesTelhado=areaCasa/(1.22*1.10);
			precoTelhado=unidadesTelhado*68.90;
			precoTotal=precoTotal+precoTelhado;
		}
		else if(escolhaTelhado==3)
		{
			menu=false;
			printf("insira o comprimento deste material (em metros): ");
			scanf("%f", &comprimentoNovoMaterialTelhado);
			printf("insira a largura deste material (em metros): ");
			scanf("%f", &larguraNovoMaterialTelhado);
			printf("insira o preço deste material: R$");
			scanf("%f", &precoNovoMaterialTelhado);
			unidadesTelhado=areaCasa/(comprimentoNovoMaterialTelhado*larguraNovoMaterialTelhado);
			precoTelhado=unidadesTelhado*precoNovoMaterialTelhado;
			precoTotal=precoTotal+precoTelhado;
		}
		else
		{
			printf("\n\nescolha invalida!\n\n");
		}
	}
	menu=true;
	system("cls");
	
	// paredes internas e externas
	float paredesInternas=0, paredesExternas=0, paredes;
	printf("\nparedes internas são as paredes que não fazem parte da estrutura da casa (paredes que dividem comodos).\n");
	printf("exemplo: se sua casa tivesse 4 comodos de mesmas medidas as paredes internas teriam a medida de %.2f metros\n\n", larguraCasa+comprimentoCasa);
	printf("insira a estensão das paredes internas (em metros): ");
	scanf("%f", &paredesInternas);
	paredesExternas=(larguraCasa*2)+(comprimentoCasa*2);
	paredes=paredesExternas+paredesInternas;
	system("cls");
	
	// area paredes
	float alturaParede=0, areaParedes=0;
	printf("insira a altura das paredes: ");
	scanf("%f", &alturaParede);
	areaParedes=alturaParede*paredes;
	system("cls");
	
	// portas e janelas
	int quantidadePortas=0, escolhaPorta=0;
	float areaPortas=0, precoPortas=0, alturaNovoMaterialPorta=0, larguraNovoMaterialPorta=0, precoNovoMaterialPorta=0;
	
	printf("quantas portas a casa vai ter: ");
	scanf("%i", &quantidadePortas);
	while(menu)
	{
		printf("modelos de porta:\n[1] porta madeira frisada (R$330,00)(2,10m x 0,80m)\n[2] outro\nsua escolha: ");
		scanf("%i", &escolhaPorta);
		if (escolhaPorta==1)
		{
			menu=false;
			areaPortas=quantidadePortas*(2.10*0.80);
			precoPortas=quantidadePortas*330;
		}
		else if(escolhaPorta==2)
		{
			menu=false;
			printf("insira a altura desta porta (em metros): ");
			scanf("%f", &alturaNovoMaterialPorta);
			printf("insira a largura desta porta (em metros): ");
			scanf("%f", &larguraNovoMaterialPorta);
			printf("insira o preço desta porta: R$");
			scanf("%f", &precoNovoMaterialPorta);
			areaPortas=quantidadePortas*(alturaNovoMaterialPorta*larguraNovoMaterialPorta);
			precoPortas=quantidadePortas*precoNovoMaterialPorta;
		}
		else
		{
			printf("\n\nescolha invalida!\n\n");
		}
	}
	menu=true;
	precoTotal=precoTotal+precoPortas;
	areaParedes=areaParedes-areaPortas;
	system("cls");
	
	int quantidadeJanelas=0, escolhaJanelas=0;
	float areaJanelas=0, precoJanelas=0, alturaNovoMaterialJanelas=0, larguraNovoMaterialJanelas=0, precoNovoMaterialJanelas=0;
	
	printf("quantas janelas a casa vai ter: ");
	scanf("%i", &quantidadeJanelas);
	while(menu)
	{
		printf("modelos de janelas:\n[1] janela aluminio slim branca (R$220,00)(1,00m x 1,10m)\n[2] janela aluminio com percianas automaticas preta(R$1.699,00)(1,00m x 1,20m)\n[3] outro\nsua escolha: ");
		scanf("%i", &escolhaJanelas);
		if (escolhaJanelas==1)
		{
			menu=false;
			areaJanelas=quantidadeJanelas*(1.0*1.10);
			precoJanelas=quantidadeJanelas*220;
		}
		else if (escolhaJanelas==2)
		{
			menu=false;
			areaJanelas=quantidadeJanelas*(1.0*1.20);
			precoJanelas=quantidadeJanelas*1699;
		}
		else if(escolhaJanelas==3)
		{
			menu=false;
			printf("insira a altura desta janela (em metros): ");
			scanf("%f", &alturaNovoMaterialJanelas);
			printf("insira a largura desta janela (em metros): ");
			scanf("%f", &larguraNovoMaterialJanelas);
			printf("insira o preço desta janela: R$");
			scanf("%f", &precoNovoMaterialJanelas);
			areaJanelas=quantidadeJanelas*(alturaNovoMaterialJanelas*larguraNovoMaterialJanelas);
			precoPortas=quantidadeJanelas*precoNovoMaterialJanelas;
		}
		else
		{
			printf("\n\nescolha invalida!\n\n");
		}
	}
	menu=true;
	precoTotal=precoTotal+precoJanelas;
	areaParedes=areaParedes-areaJanelas;
	system("cls");
	
	// materal das paredes
	int escolhaTijolo=0;
	float unidadesTijolo=0, precoTijolo=0, alturaNovoMaterialTijolo=0, larguraNovoMaterialTijolo=0, precoNovoMaterialTijolo=0;
	
	while(menu) 
	{
		printf("qual o material das paredes?\n[1] tijolo 8 furos(R$1,26)(0,19m x 0,19m)\n[2] bloco de concreto(R$3,77)(0,19m x 0,39m)\n[3] outro material\nsua escolha: ");
		scanf("%i", &escolhaTijolo);
		if(escolhaTijolo==1)
		{
			menu=false;
			unidadesTijolo=areaParedes/(0.19*0.19); 
			precoTijolo=unidadesTijolo*1.26;
			precoTotal=precoTotal+precoTijolo;
		}
		else if (escolhaTijolo==2)
		{
			menu=false;
			unidadesTijolo=areaParedes/(0.19*0.39); 
			precoTijolo=unidadesTijolo*3.77;
			precoTotal=precoTotal+precoTijolo;
		} 
		else if(escolhaTijolo==3)
		{ 
			menu=false;
			printf("insira a altura deste material (em metros): ");
			scanf("%f", &alturaNovoMaterialTijolo);
			printf("insira a largura deste material (em metros): ");
			scanf("%f", &larguraNovoMaterialTijolo);
			printf("insira o preço deste material: R$");
			scanf("%f", &precoNovoMaterialTijolo);
			unidadesTijolo=areaParedes/(alturaNovoMaterialTijolo*larguraNovoMaterialTijolo);
			precoTijolo=unidadesTijolo*precoNovoMaterialTijolo;
			precoTotal=precoTotal+precoTijolo;
		}  
		else
		{
		printf("\n\nescolha invalida!\n\n");
		}
	} 
	menu=true;
	system("cls");
	
	// reboco
	float precoMetroReboco, valorReboco;
	
	printf("insira quanto custa o metro quadrado de reboco: R$");
	scanf("%f", &precoMetroReboco);
	valorReboco=areaParedes*precoMetroReboco;
	precoTotal=precoTotal+valorReboco;
	system("cls");
	
	// mão de obra
	int escolhaPedreiro;
	float projetoEngenheiro=0, projetoArquiteto=0, tempoObra=0, precoPedreiro=0, valorTotalPedreiro=0, projetoEletricista=0, projetoEncanamento=0, precoMaoObra=0;
	
	printf("ATENÇÃO! caso o engenheiro/arquiteto façam os outros trabalhos descritos digite 0 neles\n\n");
	printf("o valor do projeto do engenheiro: R$");
	scanf("%f", &projetoEngenheiro);
	printf("o valor do projeto do arquiteto: R$");
	scanf("%f", &projetoArquiteto);	
	printf("o valor do projeto de encanamento: R$");
	scanf("%f", &projetoEncanamento);
	printf("o valor do projeto do eletricista: R$");
	scanf("%f", &projetoEletricista);
	while(menu)
	{
		printf("qual a forma de pagamento dos pedreiros?\n[1] diaria\n[2] mensal\n[3] valor unico\nsua escolha: ");
		scanf("%i", &escolhaPedreiro);
		if(escolhaPedreiro==1)
		{
			menu=false;
			printf("insira quantos meses a obra vai levar: ");
			scanf("%f", &tempoObra);
			printf("quanto o valor da diaria: R$");
			scanf("%f", &precoPedreiro);
			valorTotalPedreiro=(tempoObra*30)*precoPedreiro;
		}
		else if(escolhaPedreiro==2)
		{
			menu=false;
			printf("insira quantos meses a obra vai levar: ");
			scanf("%f", &tempoObra);
			printf("quanto o valor do mes de serviço: R$");
			scanf("%f", &precoPedreiro);
			valorTotalPedreiro=tempoObra*precoPedreiro;
		}
		else if(escolhaPedreiro==3)
		{
			menu=false;
			printf("qual será o valor total do serviço: R$");
			scanf("%f", &valorTotalPedreiro);
		}
		else
		{
			printf("\n\nescolha invalida!\n\n");
		}
	}
	menu=true;
	precoMaoObra=valorTotalPedreiro+projetoEletricista+projetoEncanamento+projetoArquiteto+projetoEngenheiro;
	precoTotal=precoTotal+precoMaoObra;
	system("cls");
	
	// +20% para tentar compesar custos que não calculamos e impostos
	precoTotal=(precoTotal/100)*120;
	
	printf("ATENÇÃO! AUMENTAMOS 20%% DO VALOR TOTAL PARA TENTARMOS COMPENSAR GASTOS QUE NÃO CALCULAMOS.\n\n");
	printf("VALOR TOTAL: %.2f\n\n", precoTotal);
	
	printf("portas: %.2f\n", precoPortas);
	printf("janelas: %.2f\n", precoJanelas);
	printf("preço fundação %.2f\n", metroFundacao*areaCasa);
	printf("mão de obra %.2f\n", precoMaoObra);
	printf("preço reboco %.2f\n", valorReboco);	
	printf("unidades tijolos: %.2f\n", unidadesTijolo);
	printf("preço tijolos: %.2f\n", precoTijolo);
	printf("total de parede: %.2f\n", paredes);
	printf("paredes internas: %.2f\n", paredesInternas);
	printf("paredes externas: %.2f\n", paredesExternas);
	printf("preço telhado: %.2f\n", precoTelhado);
	printf("unidades telhado: %.2f\n", unidadesTelhado);
	printf("area da casa: %.2f\n", areaCasa);
	printf("preço terreno: %.2f\n", precoTerreno);
	printf("\nPRESIONE ALGUMA TECLA PARA CONTINUAR...\n");
	getch();
	system("cls");
	
	printf("\nOBRIGADO POR TESTAR O MEU SOFTWARE!\n\n14/06/2024 - JOÃO PEDRO CORDASSO TRENTO (1° PERIODO ENGENHARIA DE SOFTWARE - FAG)\n\n");
	printf("PRESIONE ALGUMA TECLA PARA ENCERRAR.");
	getch();
} // fim

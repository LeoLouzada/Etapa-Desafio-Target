import org.json.JSONArray;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {

        String jsonFilePath = "faturamento.json";  // Caminho para o arquivo JSON

        try {

            BufferedReader reader = new BufferedReader(new FileReader(jsonFilePath));
            StringBuilder jsonContent = new StringBuilder();
            String line;

            while ((line = reader.readLine()) != null) {
                jsonContent.append(line);
            }
            reader.close();

            JSONArray jsonArray = new JSONArray(jsonContent.toString());

            double menorValor = Double.MAX_VALUE;
            double maiorValor = Double.MIN_VALUE;
            double soma = 0.0;
            int diasComFaturamento = 0;
            int totalDias = 0;

            for (int i = 0; i < jsonArray.length(); i++) {
                JSONObject jsonObject = jsonArray.getJSONObject(i);
                double valor = jsonObject.getDouble("valor");

                if (valor > 0) {
                    soma += valor;
                    diasComFaturamento++;
                }

                if (valor < menorValor && valor > 0) {
                    menorValor = valor;
                }

                if (valor > maiorValor) {
                    maiorValor = valor;
                }

                totalDias++;
            }

            double mediaMensal = soma / diasComFaturamento;

            int diasAcimaMedia = 0;
            for (int i = 0; i < jsonArray.length(); i++) {
                JSONObject jsonObject = jsonArray.getJSONObject(i);
                double valor = jsonObject.getDouble("valor");

                if (valor > mediaMensal) {
                    diasAcimaMedia++;
                }
            }
            
            System.out.println("Menor valor de faturamento: R$ " + menorValor);
            System.out.println("Maior valor de faturamento: R$ " + maiorValor);
            System.out.println("Número de dias com faturamento superior à média mensal: " + diasAcimaMedia);

        } catch (IOException e) {
            System.out.println("Erro ao ler o arquivo JSON: " + e.getMessage());
        }
    }
}
# Cargar librerías necesarias
if (!require("reshape2")) install.packages("reshape2")
if (!require("ggplot2")) install.packages("ggplot2")
library(reshape2)
library(ggplot2)

# Leer los datos
datos <- read.csv("resultados_repetidos.csv")
cat("[✔] Datos cargados:\n")
print(head(datos))

# Función para comparar pares
comparar_pares <- function(variable) {
  estructuras <- unique(datos$Estructura)
  cat("\n⏱ Comparaciones por pares en:", variable, "\n")
  for (i in 1:(length(estructuras)-1)) {
    for (j in (i+1):length(estructuras)) {
      grupo1 <- subset(datos, Estructura == estructuras[i])[[variable]]
      grupo2 <- subset(datos, Estructura == estructuras[j])[[variable]]
      resultado <- t.test(grupo1, grupo2)
      cat(paste0("🔸 ", estructuras[i], " vs ", estructuras[j], ": p = ", round(resultado$p.value, 5)))
      if (resultado$p.value < 0.05) cat("  ➜ Diferencia significativa ✅\n")
      else cat("  ➜ No significativa ❌\n")
    }
  }
}

# Comparar todas las operaciones
comparar_pares("Insercion")
comparar_pares("Busqueda")
comparar_pares("Eliminacion")
comparar_pares("Actualizacion")

# Generar gráfico
datos_melt <- melt(datos, id.vars = "Estructura")

ggplot(datos_melt, aes(x = variable, y = value, fill = Estructura)) +
  geom_bar(stat = "summary", fun = "mean", position = "dodge") +
  labs(title = "Comparación de estructuras por operación", x = "Operación", y = "Tiempo promedio (ms)") +
  theme_minimal()

# Guardar gráfico como imagen
ggsave("comparacion_estructuras.png", width = 8, height = 5)
cat("\n📊 Gráfico guardado como comparacion_estructuras.png ✅\n")

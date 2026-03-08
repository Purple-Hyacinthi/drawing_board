dependencies {
    implementation(project(":user"))

    implementation("org.springframework.boot:spring-boot-starter-web")
    implementation("org.springframework.boot:spring-boot-starter-security")
    implementation("org.springframework.boot:spring-boot-starter-data-jpa")
    implementation("org.springframework.boot:spring-boot-starter-validation")
    
    // JSON处理
    implementation("com.fasterxml.jackson.core:jackson-databind")
    
    testImplementation("org.springframework.boot:spring-boot-starter-test")
}

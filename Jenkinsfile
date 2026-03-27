pipeline {
    agent none

    stages {
        stage('Build Matrix') {
            matrix {

                axes {
                    axis {
                        name 'OS'
                        values 'windows', 'linux'
                    }
                    axis {
                        name 'BUILD_TYPE'
                        values 'Debug', 'Release'
                    }
                }

                agent { label "${OS}" }

                stages {

                    stage('Checkout') {
                        steps { checkout scm }
                    }

                    stage('Configure') {
                        steps {
                            script {
                                if (env.OS == 'windows') {
                                    bat """
                                        if exist build rmdir /s /q build
                                        mkdir build
                                        cmake -S . -B build -DCMAKE_BUILD_TYPE=${BUILD_TYPE}
                                    """
                                } else {
                                    sh """
                                        rm -rf build
                                        mkdir build
                                        cmake -S . -B build -DCMAKE_BUILD_TYPE=${BUILD_TYPE}
                                    """
                                }
                            }
                        }
                    }

                    stage('Build') {
                        steps {
                            script {
                                if (env.OS == 'windows') {
                                    bat "cmake --build build"
                                } else {
                                    sh "cmake --build build"
                                }
                            }
                        }
                    }

                    stage('Archive') {
                        steps {
                            archiveArtifacts artifacts: "build/**", fingerprint: true
                        }
                    }

                }
            }
        }
    }
}


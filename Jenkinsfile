pipeline {
    agent any
    environment {
       repo = "Jenkins-Test"
       tester = "${env.tester}"
    }
    stages {
    	stage('checkout') {
    		steps {
  				sh 'git clone https://github.com/teodutu/${env.repo}'
    		}
    	}
    	stage('hello') {
    		steps {
    			sh 'echo "Gonna start building..."'
    		}
    	}
    	stage('check compiler') {
    		steps {
    			sh 'gcc --version'
    		}
    	}
        stage('build helper') {
            steps {
                sh 'make build helper.o -C ${env.repo}/src && echo "Header built successully!" || echo "Failed to build!"'
            }
        }
        stage('make and build tester') {
            steps {
                sh 'ruby ${env.repo}/generators/generate_test_runner.rb ${env.repo}/tests/${env.tester}' // autogenerate Runner file for the tests
                sh 'make build -C ${env.repo}/tests && echo "Tester built successully!" || echo "Failed to build tester!"'
            }
        }
        stage('test header') {
        	steps {
                echo "Testing functions..."
        		sh 'make run -C ${env.repo}/tests'
        	}
        }
        stage('build project') {
            steps {
                sh 'make build -C ${env.repo}/src && echo "Built successully!" || echo "Failed to build!"'
            }
        }
        stage('clean') {
        	steps {
        		sh 'make -C ${env.repo} clean'
        		sh 'rm -rf ${env.repo}'
        	}
        }
    }
}
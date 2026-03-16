pipeline {
    agent any

    environment {
        JIRA_SITE = 'eip-mangrove.atlassian.net'
    }

    stages {

        stage('Checkout') {
            steps {
                echo 'Cloning repository...'
                checkout scm
            }
        }

	stage('Debug Git') {
            steps {
                sh 'git rev-parse HEAD'
                sh 'git branch'
                sh 'git remote -v'
            }
        }

        stage('Build') {
            steps {
                echo 'Building project...'
                sh 'make fclean'
                sh 'make'
            }
        }

        stage('Tests') {
            steps {
                echo 'Running tests...'
                sh 'make tests_run'
            }
        }

        stage('Cleanup') {
            steps {
                echo 'Cleaning workspace...'
                sh 'make clean'
            }
        }
    }

    post {
        always {
            echo 'Sending build info to Jira...'
            jiraSendBuildInfo(
                site: "${JIRA_SITE}",
                branch: env.BRANCH_NAME
            )
        }

        success {
            echo 'Build succeeded'
        }

        failure {
            echo 'Build failed'
        }
    }
}

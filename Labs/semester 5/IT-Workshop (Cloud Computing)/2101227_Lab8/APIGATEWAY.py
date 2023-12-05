import boto3

client = boto3.client('apigateway')


def create_api(name, description, version, types):
    response = client.create_rest_api(
        name=name,
        description=description,
        version=version,
        endpointConfiguration={'types': [types]}
    )
    return response['id']


def create_resource(apiId, parentId, pathPart):
    response = client.create_resource(
        restApiId=apiId,
        parentId=parentId,
        pathPart=pathPart
    )
    return response['id']


def get_parent_id(apiId, parent_resource_path):
    response = client.get_resources(
        restApiId=apiId,
        limit=500  # Adjust the limit as needed to list all resources
    )

    parent_resource_id = ''
    # Iterate through the resources to find the parent resource
    for resource in response['items']:
        if resource['path'] == parent_resource_path:
            parent_resource_id = resource['id']
            break
        else:
            # Handle the case where the parent resource is not found
            print(
                f"Parent resource with path '{parent_resource_path}' not found.")

    return parent_resource_id


def putMethod(apiId, authorizationType, resourceId, httpMethod):
    client.put_method(
        restApiId=apiId,
        authorizationType=authorizationType,
        resourceId=resourceId,
        httpMethod=httpMethod,
    )


def putIntegration(apiId, httpMethod, resourceId, type, integrationHttpMethod, url):
    client.put_integration(
        restApiId=apiId,
        resourceId=resourceId,
        httpMethod=httpMethod,
        type=type,
        integrationHttpMethod=integrationHttpMethod,
        uri=url
    )


def put_method_response(apiId, resourceId, httpMethod, statusCode, contentType, Model):
    client.put_method_response(
        restApiId=apiId,
        resourceId=resourceId,
        httpMethod=httpMethod,
        statusCode=statusCode,
        responseModels={
            contentType: Model,
        }
    )


def put_integration_response(apiId, resourceId, httpMethod, statusCode):
    client.put_integration_response(
        restApiId=apiId,
        resourceId=resourceId,
        httpMethod=httpMethod,
        statusCode=statusCode,
    )


def create_deployement(apiId, stageName):
    client.create_deployment(
        restApiId=apiId,
        stageName=stageName,
    )
    print("Stage Deployed successfully...")

###########################################################


name = 'portfolio'
description = 'Gateway for microservies in portfolio'
version = 'v-1'
endpointConfigurationType = 'EDGE'
authorizationType = 'NONE'
httpMethod = 'GET'
integrationHttpMethod = "GET"
type = 'HTTP'
statusCode = '200'
contentType = 'application/json'
Model = 'Empty'
stageName = 'dev'

service1 = 'http://ec2-65-0-133-40.ap-south-1.compute.amazonaws.com/'
service2 = 'http://ec2-13-127-254-77.ap-south-1.compute.amazonaws.com/'
service3 = 'http://ec2-65-1-148-153.ap-south-1.compute.amazonaws.com/'

# ***************************************************************
# ***************************************************************
print("started creating Api Gateway...")

# Define your API Gateway and resources
print("started creating Api Gateway...")

apiId = create_api(name, description, version, endpointConfigurationType)
root = get_parent_id(apiId, '/')


# Resource for /submit POST
# resourceId_submit = get_parent_id(apiId, '/')
resourceId_submit = create_resource(apiId, root, "submit")
httpMethod_submit = 'POST'
integrationHttpMethod_submit = 'POST'
user_post_url = service1 + 'submit'

putMethod(apiId, authorizationType, resourceId_submit, httpMethod_submit)
putIntegration(apiId, httpMethod_submit, resourceId_submit,
               type, integrationHttpMethod_submit, user_post_url)
put_method_response(apiId, resourceId_submit,
                    httpMethod_submit, statusCode, contentType, Model)
put_integration_response(apiId, resourceId_submit,
                         httpMethod_submit, statusCode)

# Resource for /submissions GET
resourceId_submissions = create_resource(apiId, root, "submissions")
httpMethod_submissions = 'GET'
integrationHttpMethod_submissions = 'GET'
submissions_url = service1 + 'submissions'

putMethod(apiId, authorizationType,resourceId_submissions, httpMethod_submissions)
putIntegration(apiId, httpMethod_submissions, resourceId_submissions,type, integrationHttpMethod_submissions, submissions_url)
put_method_response(apiId, resourceId_submissions,httpMethod_submissions, statusCode, contentType, Model)
put_integration_response(apiId, resourceId_submissions,httpMethod_submissions, statusCode)


# # Resource for /deletesubmission DELETE
# resourceId_deletesubmission = create_resource(
#     apiId, root, "deletesubmission")
# httpMethod_deletesubmission = 'DELETE'
# integrationHttpMethod_deletesubmission = 'DELETE'
# deletesubmission_url = service1 + 'deletesubmission'

# putMethod(apiId, authorizationType, resourceId_deletesubmission,
#           httpMethod_deletesubmission)
# putIntegration(apiId, httpMethod_deletesubmission, resourceId_deletesubmission,
#                type, integrationHttpMethod_deletesubmission, deletesubmission_url)
# put_method_response(apiId, resourceId_deletesubmission,
#                     httpMethod_deletesubmission, statusCode, contentType, Model)

# put_integration_response(
#     apiId, resourceId_deletesubmission, httpMethod_deletesubmission, statusCode)


# #######################################################################################

# # Resource for /rate POST
# resourceId_rate = get_parent_id(apiId, '/')
resourceId_rate = create_resource(apiId, root, "rate")
httpMethod_rate = 'POST'
integrationHttpMethod_rate = 'POST'
rate_url = service2 + 'rate'

# # Resource for /getrating GET
resourceId_getrating = create_resource(apiId, root, "getrating")
httpMethod_getrating = 'GET'
integrationHttpMethod_getrating = 'GET'
getrating_url = service2 + 'getrating'

# # Resource for /deleteratings DELETE
# resourceId_deleteratings = create_resource(
#     apiId, root, "deleteratings")
# httpMethod_deleteratings = 'DELETE'
# integrationHttpMethod_deleteratings = 'DELETE'
# deleteratings_url = service2 + 'deleteratings'

# # Create methods and integrations
putMethod(apiId, authorizationType, resourceId_rate, httpMethod_rate)
putIntegration(apiId, httpMethod_rate, resourceId_rate,
               type, integrationHttpMethod_rate, rate_url)
put_method_response(apiId, resourceId_rate, httpMethod_rate,
                    statusCode, contentType, Model)
put_integration_response(apiId, resourceId_rate,
                         httpMethod_rate, statusCode)

putMethod(apiId, authorizationType, resourceId_getrating, httpMethod_getrating)
putIntegration(apiId, httpMethod_getrating, resourceId_getrating,
               type, integrationHttpMethod_getrating, getrating_url)
put_method_response(apiId, resourceId_getrating,
                    httpMethod_getrating, statusCode, contentType, Model)
put_integration_response(apiId, resourceId_getrating,
                         httpMethod_getrating, statusCode)

# putMethod(apiId, authorizationType,
#           resourceId_deleteratings, httpMethod_deleteratings)
# putIntegration(apiId, httpMethod_deleteratings, resourceId_deleteratings,
#                type, integrationHttpMethod_deleteratings, deleteratings_url)
# put_method_response(apiId, resourceId_deleteratings,
#                     httpMethod_deleteratings, statusCode, contentType, Model)
# put_integration_response(apiId, resourceId_deleteratings,
#                          httpMethod_deleteratings, statusCode)

# print("successfully created resources and methods... for 2")


# # ##################################################################################


# # Resource for /recomsubmit POST
# # resourceId_recomsubmit = get_parent_id(apiId, '/')
resourceId_recomsubmit = create_resource(
    apiId, root, "recomsubmit")
httpMethod_recomsubmit = 'POST'
integrationHttpMethod_recomsubmit = 'POST'
recomsubmit_url = service3 + 'recomsubmit'

# # Resource for /recommends GET
resourceId_recommends = create_resource(
    apiId, root, "recommends")
httpMethod_recommends = 'GET'
integrationHttpMethod_recommends = 'GET'
recommends_url = service3 + 'recommends'

# # Resource for /deleterecommendations DELETE
# resourceId_deleterecommendations = create_resource(
#     apiId, root, "deleterecommendations")
# httpMethod_deleterecommendations = 'DELETE'
# integrationHttpMethod_deleterecommendations = 'DELETE'
# deleterecommendations_url = service3 + 'deleterecommendations'

# # Create methods and integrations
putMethod(apiId, authorizationType,
          resourceId_recomsubmit, httpMethod_recomsubmit)
putIntegration(apiId, httpMethod_recomsubmit, resourceId_recomsubmit,
               type, integrationHttpMethod_recomsubmit, recomsubmit_url)
put_method_response(apiId, resourceId_recomsubmit,
                    httpMethod_recomsubmit, statusCode, contentType, Model)
put_integration_response(apiId, resourceId_recomsubmit,
                         httpMethod_recomsubmit, statusCode)


putMethod(apiId, authorizationType,
          resourceId_recommends, httpMethod_recommends)
putIntegration(apiId, httpMethod_recommends, resourceId_recommends,
               type, integrationHttpMethod_recommends, recommends_url)
put_method_response(apiId, resourceId_recommends,
                    httpMethod_recommends, statusCode, contentType, Model)
put_integration_response(apiId, resourceId_recommends,
                         httpMethod_recommends, statusCode)

# putMethod(apiId, authorizationType, resourceId_deleterecommendations,
#           httpMethod_deleterecommendations)
# putIntegration(apiId, httpMethod_deleterecommendations, resourceId_deleterecommendations,
#                type, integrationHttpMethod_deleterecommendations, deleterecommendations_url)
# put_method_response(apiId, resourceId_deleterecommendations,
#                     httpMethod_deleterecommendations, statusCode, contentType, Model)
# put_integration_response(apiId, resourceId_deleterecommendations,
#                          httpMethod_deleterecommendations, statusCode)

# print("successfully created resources and methods... for3")


##########################################################################################


create_deployement(apiId, stageName)
print("successfully Deployed API...")
url = "https://"+apiId+".execute-api.ap-south-1.amazonaws.com/"+stageName+'/'
print(f"Deployment endpoint for {stageName} : {url}")

# https://ye5o3aa9yf.execute-api.ap-south-1.amazonaws.com/dev/
defmodule Cs491Hm2.Company.Employee do
  use Ecto.Schema
  import Ecto.Changeset

  schema "employees" do
    field :first_name, :string
    field :last_name, :string
    belongs_to :role, Cs491Hm2.Company.Role
    belongs_to :department, Cs491Hm2.Company.Department
    timestamps()
  end

  @spec changeset(
          {map, map}
          | %{
              :__struct__ => atom | %{:__changeset__ => map, optional(any) => any},
              optional(atom) => any
            },
          :invalid | %{optional(:__struct__) => none, optional(atom | binary) => any}) :: Ecto.Changeset.t()
  @doc false
  def changeset(employee, attrs) do
    employee
    |> cast(attrs, [:first_name, :last_name, :role_id, :department_id])
    |> validate_required([:first_name, :last_name, :role_id, :department_id])
  end
end
